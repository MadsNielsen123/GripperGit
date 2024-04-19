#include "db.h"

DB::DB() : mDb(QSqlDatabase::addDatabase("QMYSQL"))
{
        mDb.setHostName("localhost");
        mDb.setDatabaseName("SemesterProjekt3");
        mDb.setUserName("sammy");
        mDb.setPassword("password");
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

        // Hent alle rækker fra objekt-tabellen
        mQ.exec("SELECT * FROM objekt");
        while (mQ.next()) {
            int objekt_id = mQ.value(0).toInt();
            int size = mQ.value(1).toInt();
            qDebug() << "|ID:" << objekt_id << "|  |Size:" << size << "|";
        }
        std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::setfill(' ');

        // Hent alle rækker fra robot-tabellen
        mQ.exec("SELECT * FROM robot");
        while (mQ.next()) {
            int robot_id = mQ.value(0).toInt();
            QString navn = mQ.value(1).toString();
            int obj_id = mQ.value(2).toInt();
            int dag_id = mQ.value(3).toInt();
            qDebug() << "|ID:" << robot_id << "|  |Navn:" << navn << "|  |Objekt ID:" << obj_id << "|  |Dag ID:" << dag_id << "|";
}
        std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::setfill(' ');
}

void DB::insertData(){
    //if statement til når den har grebet**


    // Få det nuværende tidspunkt
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

            // Få den aktuelle dato
            std::tm *local_time = std::localtime(&now_c);
            int year = local_time->tm_year + 1900; // Tilføj 1900 til årstal, da std::tm returnerer årstal siden 1900
            int month = local_time->tm_mon + 1; // Måneder er zero-based i std::tm
            int day = local_time->tm_mday;
            int hour = local_time->tm_hour;
            int min = local_time->tm_min;
            int sec = local_time->tm_sec;
            int dag = local_time->tm_wday;

            std::ostringstream tid_oss;
            std::ostringstream dato_oss;
                    tid_oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << min << ":" << std::setw(2) << std::setfill('0') << sec;
                    std::string tid = tid_oss.str();
                    dato_oss  << year << "-" << std::setw(2) << std::setfill('0') << month << "-" << std::setw(2) << std::setfill('0') << day;
                    std::string dato = dato_oss.str();

            std::string dagen; // Deklarer variablen her

            switch (dag) {
                case 1:
                    dagen = "Mandag";
                    break;
                case 2:
                    dagen = "Tirsdag";
                    break;
                case 3:
                    dagen = "Onsdag";
                    break;
                case 4:
                    dagen = "Torsdag";
                    break;
                case 5:
                    dagen = "Fredag";
                    break;
                case 6:
                    dagen = "Lørdag";
                    break;
                case 7:
                    dagen = "Søndag";
                    break;
            }

       /*// Udskriv datoen
       std::cout << "Nuværende dato: " << dato << std::endl;
       std::cout << "Tidspunkt: " << tid << std::endl;
       std::cout << "Dag: " << dagen << std::endl;*/

       mQ.prepare("INSERT INTO dag (dato, ugedag, tidspunkt) VALUES (:dato, :ugedag, :tidspunkt)");
      // mQ.bindValue(":dag_id", dag_id); // Erstat "dag_id" med værdien for din dag_id
       mQ.bindValue(":dato", QString::fromStdString(dato));
       mQ.bindValue(":ugedag", QString::fromStdString(dagen));
       mQ.bindValue(":tidspunkt", QString::fromStdString(tid));
       mQ.exec();

       // Hent dag id til brug i objekt og robot
       mQ.prepare("SELECT dag_id FROM dag WHERE dato = :dato AND tidspunkt = :tidspunkt");
       mQ.bindValue(":dato", QString::fromStdString(dato));
       mQ.bindValue(":tidspunkt", QString::fromStdString(tid));
       mQ.exec();

       // Tjek om der er en række i resultatet
       int dag_id;
       if (mQ.next()) {
           dag_id = mQ.value(0).toInt();
       }

       //Database table dag færdig
       //-------------------------------------------------------------------------------------------------------------
       //database objekt:

       // Indsæt data til objekt
       int objekt_size = 10; //hvordan ved vi størrelsen????_______________________________________________
       mQ.prepare("INSERT INTO objekt (size) VALUES (:size)");
       mQ.bindValue(":size", objekt_size);
       mQ.exec();

       // Hent objekt id til brug i robot
       mQ.prepare("SELECT LAST_INSERT_ID()");
       mQ.exec();

       // Tjek om der er en række i resultatet
       int objekt_id;
       if (mQ.next()) {
           objekt_id = mQ.value(0).toInt();
        }

       //database table objekt færdig
       //------------------------------------------------------------------------------------------------------------------
       //database robot

      std::string robotName = "Robot1";

       // Indsæt data til robot
       //int objekt_size = 10; //hvordan ved vi størrelsen????_______________________________________________
       mQ.prepare("INSERT INTO robot (navn, objekt_id, dag_id) VALUES (:navn, :objekt_id, :dag_id)");
       mQ.bindValue(":navn", QString::fromStdString(robotName));
       mQ.bindValue(":objekt_id", objekt_id); // Brug samme dag_id som objekt_id
       mQ.bindValue(":dag_id", dag_id);
       mQ.exec();


       /*
       // Hent alle rækker fra objekt-tabellen
       mQ.exec("SELECT * FROM objekt");
       while (mQ.next()) {
           int objekt_id = mQ.value(0).toInt();
           int size = mQ.value(1).toInt();
           qDebug() << "Objekt ID:" << objekt_id << "Size:" << size;
       }

       // Hent alle rækker fra robot-tabellen
       mQ.exec("SELECT * FROM robot");
       while (mQ.next()) {
           int robot_id = mQ.value(0).toInt();
           QString navn = mQ.value(1).toString();
           int obj_id = mQ.value(2).toInt();
           int dag_id = mQ.value(3).toInt();
           qDebug() << "Robot ID:" << robot_id << "Navn:" << navn << "Objekt ID:" << obj_id << "Dag ID:" << dag_id;
       }
       */



}

