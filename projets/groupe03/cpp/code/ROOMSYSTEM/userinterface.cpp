#include "userinterface.h"
#include "ui_userinterface.h"
#include"QtSql/QSql"
#include"QtSql/QSqlError"
#include"QtSql/QSqlQuery"
#include"QMessageBox"
#include"QDate"
#include"QDir"
#include"QDebug"
#include"QtSql/QSqlDatabase"
#include"QTimer"
#include"administrateur.h"
#include"client.h"
userinterface::userinterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userinterface)
{
    ui->setupUi(this);
    ui->groupinscription->show();
    ui->groupconnexion->hide();
    ui->loading->hide();
    connect(ui->connexion,&QPushButton::clicked,this,[=](){
        ui->groupconnexion->show();
        ui->groupinscription->hide();
        ui->inscription->hide();
        ui->connexion->hide();
    });
    connect(ui->groupconnexion->findChild<QPushButton*>("inscription2"),&QPushButton::clicked,this,[=](){
        ui->groupconnexion->hide();
        ui->groupinscription->show();
        ui->inscription->show();
        ui->connexion->show();
    });
    connect(ui->groupconnexion->findChild<QPushButton*>("connexion2"),&QPushButton::clicked,this,[=](){
        QString mail=ui->groupconnexion->findChild<QTextEdit*>("mail2")->toPlainText().trimmed();
        QString mdp=ui->groupconnexion->findChild<QTextEdit*>("password2")->toPlainText().trimmed();
        QSqlQuery p;
        p.prepare("SELECT * FROM UTILISATEURS WHERE email=? AND mdp=?");
        p.addBindValue(mail);
        p.addBindValue(mdp);
        if(p.exec()&&p.next()){
            QString role=p.value("role").toString();
            if(role.toLower()=="administrateur"){
                ui->loading->setValue(0);
                ui->loading->show();
                progressValue=0;
                time=new QTimer(this);
                connect(time,&QTimer::timeout,this,&userinterface::update);
                time->start(26);
            }
            else{
                ui->loading->setValue(0);
                ui->loading->show();
                progressValue=0;
                time=new QTimer(this);
                connect(time,&QTimer::timeout,this,&userinterface::update2);
                time->start(24);

            }
        }
        else{
            QMessageBox::warning(this,"Erreur de données","Données invalides ou compte introuvable");
        }
    });
    connect(ui->inscription,&QPushButton::clicked,this,&userinterface::on_inscription_clicked);


}

userinterface::~userinterface()
{
    delete ui;
}
void userinterface::update2(){
    progressValue+=2;
    ui->loading->setValue(progressValue);
    if(progressValue>=100){
        time->stop();
        client*user=new client();
        user->show();
        this->hide();
    }
}
void userinterface::update(){
    progressValue+=2;
    ui->loading->setValue(progressValue);
    if(progressValue>=100){
        time->stop();
        administrateur*admin=new administrateur();
        admin->show();
        this->hide();
    }
}
void userinterface::updateProgress(){
    progressValue+=2;
    ui->loading->setValue(progressValue);
    if(progressValue>=100){
        time->stop();
        QString m=ui->mail->toPlainText().trimmed();
        QSqlQuery s;
        s.prepare("SELECT * FROM UTILISATEURS WHERE email=?");
        s.addBindValue(m);
        if(s.exec()&&s.next()){
            QString role=s.value("role").toString();
        if(role.toLower()=="administrateur"){
            administrateur*admin=new administrateur();
            admin->show();
            this->hide();
        }
        else{
            client*user=new client();
            user->show();
            this->hide();
        }
    }
}
}

void userinterface::on_inscription_clicked(){
    QString username= ui->username->toPlainText().trimmed();
    QString password=ui->password->toPlainText().trimmed();
    QString email=ui->mail->toPlainText().trimmed();
    QString role=ui->role->currentText().trimmed();
    QDate birthday=ui->birthday->date();
    QSqlQuery q;
    q.prepare("INSERT INTO UTILISATEURS(nom,mdp,email,role,birthday) VALUES(?,?,?,?,?)");
    q.addBindValue(username);
    q.addBindValue((password));
    q.addBindValue(email);
    q.addBindValue(role);
    q.addBindValue(birthday);
    if(q.exec()){
        ui->loading->setValue(0);
        ui->loading->show();
        progressValue=0;
        time=new QTimer(this);
        connect(time,&QTimer::timeout,this,&userinterface::updateProgress);
        time->start(25);
    }
    else{
            QMessageBox::warning(this,"Erreur","Adresse mail ou nom d'utilisateur deja utilisé ou probleme de serveur");
        }
}

