#include "secondwindow.h"
#include "ui_secondwindow.h"
#include"QApplication"
#include"QMessageBox"
#include"thirdwindow.h"
#include"QString"
SecondWindow::SecondWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);   
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
void
SecondWindow::on_btnVerify_clicked(){
    thirdwindow *third=new thirdwindow();
    third->show();
     third->thirdwindow::setSessionId(ID);
    this->hide();
}

void SecondWindow::on_btnQuit_clicked(){
    QApplication::quit();
}
void SecondWindow::setSessionId(const QString&sessionId){
    ID=sessionId;
}

