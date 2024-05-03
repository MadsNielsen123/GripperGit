#include <iostream>
#include "Db.h"

#include <thread>

using namespace std;

int main()
{
    DB DB;
    DB.insertSessionStart("Robot");
    std::this_thread::sleep_for(std::chrono::seconds(10));
    DB.insertGribStart();

    std::this_thread::sleep_for(std::chrono::seconds(10));
    DB.insertGribSlut();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    DB.insertGribStart();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    DB.insertGribSlut();

    std::this_thread::sleep_for(std::chrono::seconds(5));
    DB.insertSessionSlut();
    DB.printSession();
    DB.printGrib();



    return 0;
}
