#include "mainwindow.h"
#include <QApplication>
#include"QtSql/QSql"
#include"QtSql/QSqlError"
#include"QtSql/QSqlQuery"
#include"QMessageBox"
#include"QDate"
#include"QDir"
#include"QDebug"
#include"QtSql/QSqlDatabase"
#include"QDir"
#include"QString"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath()+"/appdata.db");
    if(db.open()){
        qDebug()<<"Base de données chargée avec succes...."<<db.databaseName();
    }
    else{
        qDebug()<<"Erreur de chargement du serveur de données"<<db.lastError().text();
    }
    QSqlQuery query;
    QString createTable=R"(CREATE TABLE IF NOT EXISTS UTILISATEURS(ID INTEGER PRIMARY KEY AUTOINCREMENT,nom TEXT UNIQUE,mdp TEXT NOT NULL,email TEXT UNIQUE,role TEXT,birthday DATE NOT NULL,valid INTEGER DEFAULT 1))";
    if(!query.exec(createTable)){
        qDebug()<<"Le chargement de vos données dans la base a échoué"<<db.lastError().text();
    }
    QString create=R"(CREATE TABLE IF NOT EXISTS SALLES(nom_salle TEXT PRIMARY KEY,description TEXT,capacite INTEGER,disponible INTEGER DEFAULT 1))";
    if(!query.exec(create)){
        qDebug()<<"Le chargement des données dans la base a échoué"<<db.lastError().text();
    }
    QString createTab=R"(CREATE TABLE IF NOT EXISTS RESERVATIONS(nom_salle TEXT PRIMARY KEY,email TEXT,date_reservation DATE,debut TIME NOT NULL,fin TIME NOT NULL,statut INTEGER DEFAULT 1))";
    if(!query.exec(createTab)){
        qDebug()<<"Le chargement des données dans la base a échoué"<<db.lastError().text();
    }
    query.exec("SELECT COUNT(*) FROM SALLES");
    int count=0;
    if(query.next()){
        count=query.value(0).toInt();
    }
    if(count==0){
        query.prepare("INSERT INTO SALLES(nom_salle,description,capacite,disponible) VALUES(?,?,?,?)");
        query.addBindValue("Amphi1000");
        query.addBindValue("La salle a un tableau numérique");
        query.addBindValue(1000);
        query.addBindValue(1);
        query.exec();
    }
        MainWindow w;
    w.show();
    return a.exec();
}
