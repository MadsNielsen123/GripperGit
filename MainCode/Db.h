#ifndef Db_H
#define Db_H

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
    ~DB(){ mDB.close(); }

    void insertSessionStart(std::string deviceName);
    void insertGribStart();

    void insertSessionSlut();
    void insertGribSlut();

    void printSession();
    void printGrib();
    
    std::vector<std::string> getLast10GripData();
    std::vector<std::string> getLast10SessionData();
    double getAverageSessionDuration();
    double getAverageGripDuration();



private:
    QSqlDatabase mDB;
    QSqlQuery mQ;
    int mSess_id, mNR;
    std::string getTime();

};

#endif // DB_H
