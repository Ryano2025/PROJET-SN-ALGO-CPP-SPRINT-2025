#ifndef RESERVER_CLIENT_H
#define RESERVER_CLIENT_H
#include"QSql"
#include"QSqlDatabase"
#include <QWidget>

namespace Ui {
class reserver_client;
}

class reserver_client : public QWidget
{
    Q_OBJECT

public:
    explicit reserver_client(QString nomAppelant,QWidget *parent = nullptr);
    ~reserver_client();
private slots:
     void reserverSalle(const QString nom);
void on_back_clicked();
private:
    Ui::reserver_client *ui;
    QSqlDatabase db=QSqlDatabase::database();
    QString nomAppelant;



};

#endif // RESERVER_CLIENT_H
