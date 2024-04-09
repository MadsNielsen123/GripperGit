#ifndef DB_H
#define DB_H

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <iomanip>


class DB
{
public:
    DB();
    ~DB(){ mDb.close(); };
    void printAll();


private:
    QSqlDatabase mDb;
    QSqlQuery mQ;

};

#endif // DB_H
