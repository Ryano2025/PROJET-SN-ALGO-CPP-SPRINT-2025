#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"QRandomGenerator"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
protected:
    void keyPressEvent(QKeyEvent*event)override;
    QTimer *blinkTimer;
    bool isLabelVisible;
};
#endif // MAINWINDOW_H
