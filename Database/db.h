#ifndef DB_H
#define DB_H

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <iomanip>
#include <sstream>

//tids data ting
#include <chrono>
#include <ctime>


class DB

{
public:
    DB();
    ~DB(){ mDb.close(); };
    void printAll();
    void insertData();


private:
    QSqlDatabase mDb;
    QSqlQuery mQ;

};

#endif // DB_H

