#include "viewuser.h"
#include "ui_viewuser.h"
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
viewuser::viewuser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::viewuser)
{
    ui->setupUi(this);
    QVBoxLayout*layout=new QVBoxLayout;
    QWidget*contenu=new QWidget;
    contenu->setLayout(layout);
    ui->view->setWidget(contenu);
    ui->view->setWidgetResizable(true);
    QSqlQuery query;
    query.prepare("SELECT nom,email,role FROM UTILISATEURS WHERE valid=1");
    query.exec();
    while(query.next()){
        QString nom=query.value("nom").toString();
        QString mail=query.value("email").toString();
        QString role=query.value("role").toString();
        QGroupBox*box=new QGroupBox(nom);
        QVBoxLayout*boxLayout=new QVBoxLayout;
        QLabel*maillbl=new QLabel("Email: "+mail);
        QLabel*rolelbl=new QLabel("Role: "+role);
        boxLayout->addWidget(maillbl);
        boxLayout->addWidget(rolelbl);
        box->setLayout(boxLayout);
        layout->addWidget(box);

    }
    layout->addStretch();
}

viewuser::~viewuser()
{
    delete ui;
}
void viewuser::on_back_clicked(){
    administrateur*a=new administrateur();
    a->show();
    this->close();
}
