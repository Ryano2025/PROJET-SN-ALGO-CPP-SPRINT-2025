#ifndef VIEWADMIN_H
#define VIEWADMIN_H
#include"QSqlDatabase"
#include <QWidget>

namespace Ui {
class viewadmin;
}

class viewadmin : public QWidget
{
    Q_OBJECT

public:
    explicit viewadmin(QWidget *parent = nullptr);
    ~viewadmin();
private slots:
    void on_back_clicked();
private:
    Ui::viewadmin *ui;
    QSqlDatabase db=QSqlDatabase::database();
};

#endif // VIEWADMIN_H
