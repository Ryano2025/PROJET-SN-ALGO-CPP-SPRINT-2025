#include "viewreserv.h"
#include "ui_viewreserv.h"
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
viewreserv::viewreserv(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::viewreserv)

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

viewreserv::~viewreserv()
{
    delete ui;
}
void viewreserv::on_back_clicked(){
        client*c=new client();
        c->show();
        this->close();

}
