#include "viewadmin.h"
#include "ui_viewadmin.h"
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
#include"administrateur.h"
viewadmin::viewadmin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::viewadmin)
{
    ui->setupUi(this);
    QVBoxLayout*layout=new QVBoxLayout;
    QWidget*contenu=new QWidget;
    contenu->setLayout(layout);
    ui->view->setWidget(contenu);
    ui->view->setWidgetResizable(true);
    QSqlQuery query;
    query.prepare("SELECT nom_salle,debut,fin FROM RESERVATIONS WHERE statut=1");
    query.exec();
    while(query.next()){
        QString nom=query.value("nom_salle").toString();
        QTime debut=query.value("debut").toTime();
        QTime fin=query.value("fin").toTime();
        QGroupBox*box=new QGroupBox(nom);
        QVBoxLayout*boxLayout=new QVBoxLayout;
        QLabel*debutlbl=new QLabel("Heure de debut:"+debut.toString("HH:mm"));
        QLabel*finlbl=new QLabel("Heure de fin:"+fin.toString("HH:mm"));
        boxLayout->addWidget(debutlbl);
        boxLayout->addWidget(finlbl);
        box->setLayout(boxLayout);
        layout->addWidget(box);

    }
    layout->addStretch();
}

viewadmin::~viewadmin()
{
    delete ui;
}
void viewadmin::on_back_clicked(){
    administrateur*a=new administrateur();
    a->show();
    this->close();
}
