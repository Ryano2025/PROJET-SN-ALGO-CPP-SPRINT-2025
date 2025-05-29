#ifndef VIEWRESERV_H
#define VIEWRESERV_H
#include"QSqlDatabase"
#include <QWidget>

namespace Ui {
class viewreserv;
}

class viewreserv : public QWidget
{
    Q_OBJECT

public:
    explicit viewreserv(QWidget *parent = nullptr);
    ~viewreserv();
private slots:
    void on_back_clicked();
private:
    Ui::viewreserv *ui;
    QSqlDatabase db=db.database();

};

#endif // VIEWRESERV_H
