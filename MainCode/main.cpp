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

    if(server.isUR()) //UR
    {
        std::cout << "Connected to UR" << std::endl;
        GripperController gripper;
        database.insertSessionStart("UR Session");

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
        std::cout << "Connected to PC" << std::endl;
        database.insertSessionStart("PC Session");

        std::vector<std::string> data;

        while(server.isConnected())
        {
            std::cout << "Ready for next command: " << std::endl;
            server.waitCommand();
            switch(server.getCommand())
            {
            case PC_EXIT:
                //server.isConnected gets set to false
                std::cout << "PC EXIT CALLED" << std::endl;
                break;

            case GET_LAST_GRIPS:
                data = database.getLast10GripData();
                std::cout << "GET LAST GRIPS CALLED" << std::endl;
                server.sendData(data);
                break;

            case GET_LAST_SESSIONS:
                data = database.getLast10SessionData();
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
                data.push_back(database.getAverageGripDuration());
                std::cout << "GET AVERAGE GRIP DURATION CALLED" << std::endl;
                server.sendData(data);
                break;

            default:
                std::cout << "Bad command. Terminating program." << std::endl;
                break;
            }
            data.clear();
        }

        sleep(2);
        server.terminate();
        database.insertSessionSlut();
    }

    return 0;
}
