#include <QCoreApplication>
#include <iostream>
#include <server.h>
#include <GripperController.h>
#include <Db.h>

int main()
{
    Server server;
    server.waitConnection();
    DB database;

    if(server.isUR())
    {
        std::cout << "Connected to UR" << std::endl;
        GripperController gripper;
        database.insertSessionStart("UR TEST");

        while(server.isConnected())
        {
            server.waitCommand();
            switch(server.getCommand())
            {
            case GRIPPER_EXIT:
                //server.isConnected gets set to false
                server.clientContinue();
                break;

            case GRIPPER_GRIP:
                database.insertGribStart();
                gripper.grip();
                server.clientContinue();
                break;

            case GRIPPER_OPEN:
                gripper.open();
                database.insertGribSlut();
                server.clientContinue();
                break;

            case GRIPPER_INIT:
                gripper.open();
                server.clientContinue();
                break;
            }
        }
        server.terminate();
        database.insertSessionSlut();
    }
    else //PC
    {
        server.clientContinue();
        std::cout << "Connected to PC" << std::endl;
        database.insertSessionStart("PC TEST");

        std::vector<std::string> data;
        data.push_back("Data1");
        data.push_back("Data2");
        data.push_back("Data3");
        data.push_back("Data4");
        data.push_back("Data5");

        while(server.isConnected())
        {
            std::cout << "Ready for next command: " << std::endl;
            server.waitCommand();
            switch(server.getCommand())
            {
            case PC_EXIT:
                //server.isConnected gets set to false
                std::cout << "PC EXIT CALLED" << std::endl;
                break;std::cout << "PC EXIT CALLED" << std::endl;

            case GET_LAST_GRIPS:
                data.push_back(database.getLast10GripData());
                // hvis denne ikke virker -------->
                // std::vector<std::string> gripData = database.getLast10GripData();
                // data.push_back(gripData);
                
                std::cout << "GET LAST GRIPS CALLED" << std::endl;
                server.sendData(data);
                break;

            case GET_LAST_SESSIONS:
                data.push_back(database.getLast10sessionData());
                // hvis denne ikke virker -------->
                // std::vector<std::string> sessionData = database.getLast10SessionData();
                // data.push_back(sessionData);
                std::cout << "GET LAST SESSION CALLED" << std::endl;
                server.sendData(data);
                break;

            case GET_AVERAGE_SIZE:
                //fylder data med data.push_back(); 
                //ingen metode til at gemme størrelse i nu
                
                std::cout << "GET_AVERAGE_SIZE CALLED" << std::endl;
                server.sendData(data);
                break;

            case GET_AVERAGE_SESSION_DURATION:
                data.push_back(database.getAverageSessionDuration());
                
                std::cout << "GET AVERAGER SESSION DURATION CALLED" << std::endl;
                server.sendData(data);
                break;
            case GET_AVERAGE_GRIP_DURATION:
                //rune fylder data med data.push_back();
                data.push_back(database.getAverageGripDuration());
                
                std::cout << "GET AVERAGE GRIP DURATION CALLED" << std::endl;
                server.sendData(data);
                break;
            }
            //data.clear();
        }

        sleep(2);
        server.terminate();
        database.insertSessionSlut();
    }

    return 0;
}
