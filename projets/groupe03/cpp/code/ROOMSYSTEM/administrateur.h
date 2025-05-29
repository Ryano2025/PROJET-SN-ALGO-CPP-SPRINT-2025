#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H
#include"QtSql/QSqlDatabase"
#include <QWidget>

namespace Ui {
class administrateur;
}

class administrateur : public QWidget
{
    Q_OBJECT

public:
    explicit administrateur(QWidget *parent = nullptr);
    ~administrateur();
private slots:
    void on_btnView_clicked();
    void on_btnReserve_clicked();
    void on_btnViewUser_clicked();
    void on_btnAjouter_clicked();
    void on_btnDisponible_clicked();
    void on_back_clicked();
private:
    Ui::administrateur *ui;
    QSqlDatabase db=QSqlDatabase::database();

};

#endif // ADMINISTRATEUR_H
