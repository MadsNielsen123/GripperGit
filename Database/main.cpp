#include <QCoreApplication>
#include <string>
#include <iostream>
#include "db.h"
#include "db.h"
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
DB DB;


DB.insertData();
DB.printAll();

    //    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setDatabaseName("SemesterProjekt");
//    db.setUserName("root");
//    db.setPassword("1234");
//    db.open();

//    QSqlQuery query;

//    query.exec("select * from robot;");

//    while(query.next()){
//       QString dag_id = query.value(0).toString();
//       QString dato = query.value(1).toString();
//       QString ugedag = query.value(2).toString();
//       QString tidspunkt = query.value(3).toString();

        //qDebug() << "id" <<  dag_id  << "s" << dato;
//       qDebug() << "id: " << dag_id << "dato: " << dato << "ugedag: " << ugedag << "tidspunkt" << tidspunkt;
//    }

    return 0;
}

