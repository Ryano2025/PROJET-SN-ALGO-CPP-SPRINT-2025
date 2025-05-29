#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QWidget>
#include"QString"

namespace Ui {
class thirdwindow;
}

class thirdwindow : public QWidget
{
    Q_OBJECT

public:
    explicit thirdwindow(QWidget *parent = nullptr);
    ~thirdwindow();
    void setSessionId(const QString&id);
private slots:
    void on_btnQuit1_clicked();
    void on_btnConfirm_clicked();

private:
    Ui::thirdwindow *ui;
};

#endif // THIRDWINDOW_H
