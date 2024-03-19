#include <QCoreApplication>
#include <iostream>
#include <pigpio.h>
#include <unistd.h> // For sleep functions usleep and nanosleep)

int main(int argc, char *argv[])
{
    if (gpioInitialise() < 0)
    {
       // pigpio initialisation failed.
       std::cout << "GPIO Init Failed - Closing program" << std::endl;
       return 1;
    }
    else
    {
       // pigpio initialised okay.
    }
    
    gpioSetMode(23, PI_OUTPUT); // Set GPIO23 as output.
    
    gpioPWM(23, 128); // Sets GPIO23 half on.
    usleep(20000000);    // Wait 20 seconds
    /*
    // Blink the LED 10 times
    for (int i = 0; i < 10; ++i)
    {
        gpioWrite(23, 1); // Set GPIO23 high (LED ON)
        usleep(200000);    // Sleep for 500 milliseconds (0.5 seconds)
        gpioWrite(23, 0); // Set GPIO23 low (LED OFF)
        usleep(200000);    // Sleep for 500 milliseconds (0.5 seconds)
    }
    
    std::cout << "Jeg har blinket 10 gange" << std::endl;
    
    */
    
    
    usleep(100000);    // Wait for 100 milliseconds for gpioTerminate to be ready
    gpioTerminate(); //Reset gpio, ram ect. after program done
    return 0;
}
