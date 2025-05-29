#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include"QString"
#include"QStack"
#include"QChar"
#include"QMessageBox"
#include"secondwindow.h"

thirdwindow::thirdwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
}

thirdwindow::~thirdwindow()
{
    delete ui;
}
void thirdwindow::on_btnQuit1_clicked(){
    QApplication::quit();
}
bool ParenthesesEquilibrees(const QString &exp){
    QStack<QChar> stack;
    QMap<QChar,QChar>paire;
    paire[')']='(';
    paire['}']='{';
    paire[']']='[';
    for(QChar e:exp){
        if(paire.values().contains(e)){
            stack.push(e);
        }
        else if(paire.contains(e)){
            if(stack.empty()||stack.top()!=paire[e]){
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();

}
    void thirdwindow::on_btnConfirm_clicked(){
    QString expression=ui->textExpression->toPlainText();
    if(ParenthesesEquilibrees(expression)){
        QMessageBox::information(this,"RESULTAT DE VERIFICATION","L'expression est a parentheses equilibrées");
    }
    else{
        QMessageBox::warning(this,"RESULTAT DE VERIFICATION","L'expression que vous avez entré n'est pas a parentheses equilibrées");
    }
}
    void thirdwindow::setSessionId(const QString&id){
        ui->lblSessionId->setText("ID DE SESSION:"+id);
    }



