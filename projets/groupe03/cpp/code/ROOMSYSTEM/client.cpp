#include "client.h"
#include "ui_client.h"
#include"reserver_client.h"
#include"dispo.h"
#include"viewreserv.h"
#include"userinterface.h"
client::client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}
void client::on_btnReserve_clicked(){
    reserver_client*reservation=new reserver_client("client");
    reservation->show();
    this->hide();
}
void client::on_btnDisponible_clicked(){
    dispo*a=new dispo("client");
    a->show();
    this->hide();
}
void client::on_btnVoir_clicked(){
    viewreserv*v=new viewreserv();
    v->show();
    this->hide();

}
void client::on_back_clicked(){
    userinterface*u=new userinterface();
    u->show();
    this->close();
}
