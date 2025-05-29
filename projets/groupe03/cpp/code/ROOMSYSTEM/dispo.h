#ifndef DISPO_H
#define DISPO_H
#include"QSqlDatabase"
#include <QWidget>

namespace Ui {
class dispo;
}

class dispo : public QWidget
{
    Q_OBJECT

public:
    explicit dispo(QString nomAppelant,QWidget *parent = nullptr);
    ~dispo();
private slots:
    void on_back_clicked();

private:
    Ui::dispo *ui;
    QSqlDatabase db=QSqlDatabase::database();
    QString nomAppelant;

};

#endif // DISPO_H
