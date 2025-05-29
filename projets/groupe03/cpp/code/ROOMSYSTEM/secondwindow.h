#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>

namespace Ui {
class secondwindow;
}

class secondwindow : public QWidget
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();
private slots:
    void verifierCondition();
    void on_btnContinue_clicked();
    void startNextWindow();
private:
    Ui::secondwindow *ui;
protected:
    QTimer*blinkTimer;
    bool isLabelVisible;

};


#endif // SECONDWINDOW_H
