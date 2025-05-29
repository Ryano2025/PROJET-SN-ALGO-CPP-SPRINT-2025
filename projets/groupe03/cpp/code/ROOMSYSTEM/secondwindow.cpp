#include "secondwindow.h"
#include "ui_secondwindow.h"
#include"QTimer"
#include"userinterface.h"

secondwindow::secondwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    connect(ui->lblcheckBox1,&QCheckBox::stateChanged,this,&secondwindow::verifierCondition);
    connect(ui->lblcheckBox2,&QCheckBox::stateChanged,this,&secondwindow::verifierCondition);
    ui->btnContinue->setEnabled(false);
}
secondwindow::~secondwindow()
{
    delete ui;
}
void secondwindow::verifierCondition(){
    bool a=ui->lblcheckBox1->isChecked();
    bool b=ui->lblcheckBox2->isChecked();
    ui->btnContinue->setEnabled(a&&b);

}
void secondwindow::startNextWindow(){
    userinterface*user=new userinterface();
    user->show();
    this->hide();
}
void secondwindow::on_btnContinue_clicked(){
    ui->lblCharge->setText("chargement...");
    blinkTimer=new QTimer(this);
    isLabelVisible=false;
    connect(blinkTimer,&QTimer::timeout,this,[=](){
        isLabelVisible=!isLabelVisible;
        ui->lblCharge->setVisible(isLabelVisible);
    });
    blinkTimer->start(500);
    QTimer::singleShot(2000,this,SLOT(startNextWindow()));
}

