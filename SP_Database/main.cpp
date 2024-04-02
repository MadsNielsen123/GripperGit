#include <QCoreApplication>
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <string>

class connectSql;
int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("SemesterProjekt");
    db.setUserName("root");
    db.setPassword("1234");
    db.open();

    QSqlQuery query;

    query.exec("SELECT * FROM dag");

    while(query.next()){
       QString dag_id = query.value(0).toString();
       QString dato = query.value(1).toString();
       QString ugedag = query.value(2).toString();
       QString tidspunkt = query.value(3).toString();

        //qDebug() << "id" <<  dag_id  << "s" << dato;
       qDebug() << "id: " << dag_id << "dato: " << dato << "ugedag: " << ugedag << "tidspunkt" << tidspunkt;
    }

    return 0;
}

