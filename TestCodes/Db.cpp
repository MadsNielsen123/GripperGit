#include "Db.h"

DB::DB() : mDB(QSqlDatabase::addDatabase("QMYSQL"))
{
        mDB.setHostName("localhost");
        mDB.setDatabaseName("GripperDB");
        mDB.setUserName("root");
        mDB.setPassword("123");
        mDB.open();
}

void DB::insertSessionStart(std::string deviceName){
    // Få det nuværende tidspunkt
    std::string dato_tid = getTime();

    mQ.prepare("INSERT INTO session (tid_start, device_name) VALUES (:tid_start, :device_name)");
    mQ.bindValue(":tid_start", QString::fromStdString(dato_tid));
    mQ.bindValue(":device_name", QString::fromStdString(deviceName));
    mQ.exec();

    //får sess_id på det igangværende session
    mQ.prepare("SELECT sess_id FROM session WHERE tid_start = :tid_start");
    mQ.bindValue(":tid_start", QString::fromStdString(dato_tid));

    if (mQ.exec()){
        if (mQ.next()){
            int id = mQ.value(0).toInt();
            mSess_id = id;
        } else
            qDebug() << "ingen resultater fundet";
    } else
        qDebug() << "Fejl under udførelsen: " << mQ.lastError().text();

     std::cout << "Dato og tid: " << dato_tid << " indsættes i database session med id: " << mSess_id << std::endl;
}

void DB::insertGribStart(){
    // Få det nuværende tidspunkt
    std::string dato_tid = getTime();

       mQ.prepare("INSERT INTO grib (tid_start, sess_id) VALUES (:tid_start, :sess_id)");
       mQ.bindValue(":tid_start", QString::fromStdString(dato_tid));
       mQ.bindValue(":sess_id", mSess_id);
       mQ.exec();

       //får nr på det igangværende grib
       mQ.prepare("SELECT nr FROM grib WHERE tid_start = :tid_start");
       mQ.bindValue(":tid_start", QString::fromStdString(dato_tid));
       if (mQ.exec()){
           if (mQ.next()){
               int id = mQ.value(0).toInt();
               mNR = id;
           } else
               qDebug() << "ingen resultater fundet";
       } else
           qDebug() << "Fejl under udførelsen: " << mQ.lastError().text();

       std::cout << "Dato og tid: " << dato_tid << " indsættes i database grib ved greb nr: " << mNR << std::endl;
}

void DB::insertSessionSlut(){
    //tager det nye tidspunkt
    std::string dato_tid = getTime();

    //opdatere den igangværende sessions slut tid
    mQ.prepare("UPDATE session SET tid_slut = :tid_slut Where sess_id = :sess_id");
    mQ.bindValue(":tid_slut", QString::fromStdString(dato_tid));
    mQ.bindValue(":sess_id", mSess_id);
    mQ.exec();
}

void DB::insertGribSlut(){
    //tager det nye tidspunkt
    std::string dato_tid = getTime();

    //opdatere den igangværende sessions slut tid
    mQ.prepare("UPDATE grib SET tid_slut = :tid_slut Where nr = :nr");
    mQ.bindValue(":tid_slut", QString::fromStdString(dato_tid));
    mQ.bindValue(":nr", mNR);
    mQ.exec();
}

void DB::printSession(){
    std::cout << "Tidspunkter for en session" << std::endl;
    mQ.exec("SELECT * FROM session");
    while (mQ.next()){
        int sess_id = mQ.value(0).toInt();
        QString tid_start = mQ.value(1).toString();
        QString tid_slut = mQ.value(2).toString();
        QString name = mQ.value(3).toString();

        //formatere tiden (start) fra (yyy-MM-ddTHH:mm:ss.zzz) to (dd/mm/yyyy hh:mm:ss AP)
        QDateTime time_start = QDateTime::fromString(tid_start, "yyyy-MM-ddTHH:mm:ss.zzz");
        QString formattedTime_start = time_start.toString("dd/MM/yyyy hh:mm:ss"); //Uden AM og PM
        //QString formattedTime = dateTime.toString("dd/MM/yyyy hh:mm:ss AP"); //med AM og PM

        //formatere tiden (stop) fra (yyy-MM-ddTHH:mm:ss.zzz) to (dd/mm/yyyy hh:mm:ss AP)
        QDateTime time_slut = QDateTime::fromString(tid_slut, "yyyy-MM-ddTHH:mm:ss.zzz");
        QString formattedTime_slut = time_slut.toString("dd/MM/yyyy hh:mm:ss"); //Uden AM og PM
        //QString formattedTime = dateTime.toString("dd/MM/yyyy hh:mm:ss AP"); //med AM og PM

        qDebug() << "|Sess id:" << sess_id << "|  |Tid_start:" << formattedTime_start << "|  |tid_sliut:" << formattedTime_slut << "|  |Name:" << name << "|";
    }

}

void DB::printGrib(){
    std::cout << "Tidspunkter et greb er registreret: " << std::endl;
    mQ.exec("SELECT * FROM grib");
    while (mQ.next()){
        int nr = mQ.value(0).toInt();
        QString tid_start = mQ.value(1).toString();
        QString tid_slut = mQ.value(2).toString();
        int size = mQ.value(3).toInt();
        int sess_id = mQ.value(4).toInt();

        //formatere tiden (start) fra (yyy-MM-ddTHH:mm:ss.zzz) to (dd/mm/yyyy hh:mm:ss AP)
        QDateTime time_start = QDateTime::fromString(tid_start, "yyyy-MM-ddTHH:mm:ss.zzz");
        QString formattedTime_start = time_start.toString("dd/MM/yyyy hh:mm:ss"); //Uden AM og PM
        //QString formattedTime = dateTime.toString("dd/MM/yyyy hh:mm:ss AP"); //med AM og PM

        //formatere tiden (stop) fra (yyy-MM-ddTHH:mm:ss.zzz) to (dd/mm/yyyy hh:mm:ss AP)
        QDateTime time_slut = QDateTime::fromString(tid_slut, "yyyy-MM-ddTHH:mm:ss.zzz");
        QString formattedTime_slut = time_slut.toString("dd/MM/yyyy hh:mm:ss"); //Uden AM og PM
        //QString formattedTime = dateTime.toString("dd/MM/yyyy hh:mm:ss AP"); //med AM og PM

        qDebug() << "|NR:" << nr << "|  |Tid_start:" << formattedTime_start << "|  |tid_sliut:" << formattedTime_slut << "|  |Size:" << size << "|  |Sess_id:" << sess_id << "|";
    }

}

std::string DB::getTime(){
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


        //laver om til string format
        std::ostringstream dato_tid_oss;
                dato_tid_oss << year << "-" << std::setw(2) << std::setfill('0') << month << "-" << std::setw(2) << std::setfill('0') << day << " "
                         << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << min << ":" << std::setw(2) << std::setfill('0') << sec;
                std::string dato_tid = dato_tid_oss.str();

        return dato_tid;
}

