#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QKeyEvent"
#include"QMessageBox"
#include"QRandomGenerator"
#include"secondwindow.h"
#include"QTimer"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    blinkTimer=new QTimer(this);
    isLabelVisible=true;
    connect(blinkTimer , &QTimer::timeout,this,[=](){
        isLabelVisible= !isLabelVisible;
    ui->labelInstruction->setVisible(isLabelVisible);
    });
    blinkTimer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent*event){
    if(event->key()==Qt::Key_Return || event->key()==Qt::Key_Enter){
         int sessionId=QRandomGenerator::global()->bounded(1000,9999);
        QString idText="Votre identifiant de session est: ID-"+QString::number(sessionId);
        QMessageBox::information(this,"Identifiant de Session",idText);
        SecondWindow *second=new SecondWindow();
        second->show();
         second->SecondWindow::setSessionId(idText);
        this->hide();
    }

}

