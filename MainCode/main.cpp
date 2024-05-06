#include <QCoreApplication>
#include <iostream>
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
                server.URContinue();
                break;

            case GRIPPER_GRIP:
                database.insertGribStart();
                gripper.grip();
                server.URContinue();
                break;

            case GRIPPER_OPEN:
                gripper.open();
                database.insertGribSlut();
                server.URContinue();
                break;

            case GRIPPER_INIT:
                gripper.open();
                server.URContinue();
                break;
            }
        }
        server.terminate();
        database.insertSessionSlut();
    }
    else //PC
    {
        std::cout << "Connected to PC" << std::endl;
        database.insertSessionStart("PC TEST");
       /* while(server.isConnected())
        {
            //Poul
        }*/
        sleep(2);
        server.terminate();
        database.insertSessionSlut();
    }

    return 0;
}
