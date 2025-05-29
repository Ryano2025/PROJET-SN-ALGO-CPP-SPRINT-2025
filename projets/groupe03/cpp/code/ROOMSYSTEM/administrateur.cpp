#include "administrateur.h"
#include "ui_administrateur.h"
#include"viewadmin.h"
#include"reserver_client.h"
#include"viewuser.h"
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
#include"QVBoxLayout"
#include"QLabel"
#include"QTimeEdit"
#include"QPushButton"
#include"QDialog"
#include"QGroupBox"
#include"QTextEdit"
#include"QLineEdit"
#include"dispo.h"
#include"userinterface.h"
#include"client.h"
administrateur::administrateur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::administrateur)
{
    ui->setupUi(this);
}

administrateur::~administrateur()
{
    delete ui;
}
void administrateur::on_btnView_clicked(){
    viewadmin*voir=new viewadmin();
    voir->show();
    this->hide();
}
void administrateur::on_btnReserve_clicked(){
    reserver_client*classclient=new reserver_client("administrateur");
    classclient->show();
    this->hide();
}
    void administrateur::on_btnViewUser_clicked(){
        viewuser*users=new viewuser();
        users->show();
        this->hide();
    }
    void administrateur::on_btnAjouter_clicked(){
        QDialog*dialog=new QDialog(this);
        dialog->setWindowTitle("Ajouter une salle");
        QLabel*nomlbl=new QLabel("Nom:  ",dialog);
        QTextEdit*nomText=new QTextEdit(dialog);
        QLabel*descriptlbl=new QLabel("Description: ",dialog);
        QTextEdit*desText=new QTextEdit(dialog);
        QLabel*capalbl=new QLabel("Capacite: ",dialog);
        QLineEdit*capText=new QLineEdit(dialog);
        QPushButton*btnAjout=new QPushButton("Ajouter cette salle",dialog);
        QPushButton*btnAnnuler=new QPushButton("Annuler",dialog);
        QVBoxLayout*layout=new QVBoxLayout(dialog);
        layout->addWidget(nomlbl);
        layout->addWidget(nomText);
        layout->addWidget(descriptlbl);
        layout->addWidget(desText);
         layout->addWidget(capalbl);
         layout->addWidget(capText);
        layout->addWidget(btnAjout);
        layout->addWidget(btnAnnuler);
        dialog->setLayout(layout);
        connect(btnAnnuler,&QPushButton::clicked,dialog,&QDialog::reject);
        connect(btnAjout,&QPushButton::clicked,this,[=](){
            QString nom=nomText->toPlainText();
            QString description=desText->toPlainText();
            QString capacite=capText->text();
            if(!capText->text().toInt(nullptr,10)&&capText->text()!="0"){
                QMessageBox::warning(dialog,"Erreur","la capacité doit etre un entier");
                return;
            }
            QSqlQuery query;
            query.prepare("INSERT INTO SALLES(nom_salle,description,capacite) VALUES(?,?,?)");
            query.addBindValue(nom);
            query.addBindValue(description);
            query.addBindValue(capacite);

            if(!query.exec()){
                QMessageBox::critical(dialog,"Erreur","Erreur d'insertion de salle "+query.lastError().text());
                return;
            }
            else {

                  QMessageBox::information(dialog,"Succes","la salle a été ajoutée"+query.lastError().text());
            }
        });
        dialog->exec();
    }
    void administrateur::on_btnDisponible_clicked(){
        dispo*d=new dispo("administrateur");
        d->show();
        this->hide();
    }
    void administrateur::on_back_clicked(){
        userinterface*i=new userinterface();
        i->show();
        this->close();
    }
