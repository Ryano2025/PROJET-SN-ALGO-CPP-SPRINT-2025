#include "dispo.h"
#include "ui_dispo.h"
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
#include"client.h"
#include"administrateur.h"
dispo::dispo(QString nomAppelant,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dispo)
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
        boxLayout->addWidget(capacitelbl);
        boxLayout->addWidget(dispolbl);
        boxLayout->addWidget(descriptlbl);
        box->setLayout(boxLayout);
        layout->addWidget(box);

    }
    layout->addStretch();
}

dispo::~dispo()
{
    delete ui;
}
void dispo::on_back_clicked(){
    if(nomAppelant=="administrateur"){
        administrateur*ad=new administrateur();
        ad->show();
        this->close();
        return;
    }
    else if(nomAppelant=="client"){
        client*cl=new client();
        cl->show();
        this->close();
    }
}

