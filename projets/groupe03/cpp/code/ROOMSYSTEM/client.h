#ifndef CLIENT_H
#define CLIENT_H
#include"QtSql/QSqlDatabase"
#include <QWidget>

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
private slots:
 void on_btnReserve_clicked();
    void on_btnDisponible_clicked();
 void on_btnVoir_clicked();
void on_back_clicked();
private:
    Ui::client *ui;
     QSqlDatabase db=QSqlDatabase::database();

};

#endif // CLIENT_H
