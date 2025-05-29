#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include"QString"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void setSessionId(const QString& sessionId);
    QString ID;

private slots:
    void on_btnVerify_clicked();
    void on_btnQuit_clicked();

private:
    Ui::SecondWindow *ui;
};


#endif // SECONDWINDOW_H
