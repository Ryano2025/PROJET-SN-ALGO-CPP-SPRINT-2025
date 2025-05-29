#include "reserver_client.h"
#include "ui_reserver_client.h"
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
#include"QVBoxLayout"
#include"QLabel"
#include"QTimeEdit"
#include"QPushButton"
#include"QDialog"
#include"client.h"
#include"administrateur.h"
reserver_client::reserver_client(QString nomAppelant,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reserver_client)
    ,nomAppelant(nomAppelant)
{
    ui->setupUi(this);
    QVBoxLayout*layout=new QVBoxLayout;
    QWidget*contenu=new QWidget;
    contenu->setLayout(layout);
    ui->view->setWidget(contenu);
    ui->view->setWidgetResizable(true);
    QSqlQuery query;
    query.prepare("SELECT nom_salle,capacite,description FROM SALLES WHERE disponible=1");
    query.exec();
    while(query.next()){
        QString nom=query.value("nom_salle").toString();
        int capacite=query.value("capacite").toInt();
        QString description=query.value("description").toString();
        QGroupBox*box=new QGroupBox(nom);
        QVBoxLayout*boxLayout=new QVBoxLayout;
        QLabel*capacitelbl=new QLabel("La capacite de la salle est de:"+QString::number(capacite));
        QLabel*dispolbl=new QLabel("Statut: Disponible");
        QLabel*descriptlbl=new QLabel(description);
        QPushButton*btnReserve=new QPushButton("Reserver");
        connect(btnReserve,&QPushButton::clicked,this,[=](){
            reserver_client::reserverSalle(nom);
        });
        boxLayout->addWidget(capacitelbl);
        boxLayout->addWidget(dispolbl);
        boxLayout->addWidget(descriptlbl);
        boxLayout->addWidget(btnReserve);
        box->setLayout(boxLayout);
        layout->addWidget(box);

    }
    layout->addStretch();
}

reserver_client::~reserver_client()
{
    delete ui;
}
void reserver_client::reserverSalle(const QString nom){
    QDialog*dialog=new QDialog(this);
    dialog->setWindowTitle("Reserver la salle"+nom);
    QLabel*lbldebut=new QLabel("Heure de debut: ",dialog);
    QTimeEdit*timeDebut=new QTimeEdit(QTime::currentTime(),dialog);
    QLabel*lblfin=new QLabel("Heure de fin: ",dialog);
    QTimeEdit*timeFin=new QTimeEdit(QTime::currentTime(),dialog);
    QPushButton*btnConfirmer=new QPushButton("Confirmer la reservation",dialog);
    QPushButton*btnAnnuler=new QPushButton("Annuler",dialog);
    QVBoxLayout*layout=new QVBoxLayout(dialog);
    layout->addWidget(lbldebut);
    layout->addWidget(timeDebut);
    layout->addWidget(lblfin);
    layout->addWidget(timeFin);
    layout->addWidget(btnConfirmer);
    layout->addWidget(btnAnnuler);
    dialog->setLayout(layout);
    connect(btnAnnuler,&QPushButton::clicked,dialog,&QDialog::reject);
    connect(btnConfirmer,&QPushButton::clicked,this,[=](){
        QTime debut=timeDebut->time();
        QTime fin=timeFin->time();
        if(debut>fin){
            QMessageBox::warning(dialog,"Erreur","l'heure de fin doit etre apres l'heure de debut");
            return;
        }
        QSqlQuery query;
        query.prepare("INSERT INTO RESERVATIONS(nom_salle,debut,fin) VALUES(?,?,?)");
        query.addBindValue(nom);
        query.addBindValue(debut);
        query.addBindValue(fin);
        if(!query.exec()){
            QMessageBox::critical(dialog,"Erreur","Salle indisponible ou erreur d'enregistrement "+query.lastError().text());
            return;
        }
        QMessageBox::information(dialog,"Succes","Salle reservée pendant la période choisie "+query.lastError().text());

});
    dialog->exec();
}
void reserver_client::on_back_clicked(){
    if(nomAppelant=="administrateur"){
        administrateur*admin=new administrateur();
        admin->show();
        this->close();
        return;
    }
    else if(nomAppelant=="client"){
        client*cli=new client();
        cli->show();
        this->close();
    }

}
