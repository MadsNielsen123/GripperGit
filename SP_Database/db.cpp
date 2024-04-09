#include "db.h"

DB::DB() : mDb(QSqlDatabase::addDatabase("QMYSQL"))
{
        mDb.setHostName("localhost");
        mDb.setDatabaseName("SemesterProjekt");
        mDb.setUserName("root");
        mDb.setPassword("1234");
        mDb.open();


}

void DB::printAll()
{
    mQ.exec("select * from dag");

    std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::setfill(' ');

        while(mQ.next())
        {
           QString dag_id = mQ.value(0).toString();
           QString dato = mQ.value(1).toString();
           QString ugedag = mQ.value(2).toString();
           QString tidspunkt = mQ.value(3).toString();
           qDebug().noquote().nospace() << "|id: " << dag_id << "|  |dato: " << dato << "|  |ugedag: " << ugedag << "|  |tidspunkt: " << tidspunkt <<"|";

        }

        std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::setfill(' ');



}
