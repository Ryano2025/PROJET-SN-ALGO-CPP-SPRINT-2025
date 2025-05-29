#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QKeyEvent"
#include"QMessageBox"
#include"QTimer"
#include"secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    blinkTimer=new QTimer(this);
    isLabelVisible=true;
    connect(blinkTimer , &QTimer::timeout,this,[=](){
        isLabelVisible= !isLabelVisible;
        ui->lblStart->setVisible(isLabelVisible);
    });
    blinkTimer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::startNextWindow(){
    secondwindow*second=new secondwindow();
    second->show();
    this->hide();
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Return||event->key()==Qt::Key_Enter){
        ui->lblStart->setText("CHARGEMENT...");
        QTimer::singleShot(3000,this,SLOT(startNextWindow()));

    }
}
