#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include"QtSql/QSqlDatabase"
#include <QWidget>

namespace Ui {
class userinterface;
}

class userinterface : public QWidget
{
    Q_OBJECT

public:
    explicit userinterface(QWidget *parent = nullptr);
    ~userinterface();
    void on_inscription_clicked();

private:
    Ui::userinterface *ui;
   QSqlDatabase db=QSqlDatabase::database();
    QTimer *time;
   int progressValue;
    void updateProgress();
   void update();
    void update2();
};

#endif // USERINTERFACE_H
