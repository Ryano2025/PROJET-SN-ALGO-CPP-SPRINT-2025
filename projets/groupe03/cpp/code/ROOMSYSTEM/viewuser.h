#ifndef VIEWUSER_H
#define VIEWUSER_H
#include"QSqlDatabase"
#include <QWidget>

namespace Ui {
class viewuser;
}

class viewuser : public QWidget
{
    Q_OBJECT

public:
    explicit viewuser(QWidget *parent = nullptr);
    ~viewuser();
private slots:
    void on_back_clicked();
private:
    Ui::viewuser *ui;
    QSqlDatabase db=QSqlDatabase::database();
};

#endif // VIEWUSER_H
