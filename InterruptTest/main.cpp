#include <pigpio.h>
#include <iostream>
#include <chrono>

// Global variables for debounce
std::chrono::steady_clock::time_point last_isr_time;
const int DEBOUNCE_TIME_MS = 50;

// Callback function for alert event
void alertCallback(int gpio, int level, uint32_t tick) {
    // Get the current time
    auto current_time = std::chrono::steady_clock::now();

    // Calculate the time elapsed since the last ISR trigger
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_isr_time).count();

    // Ignore the ISR trigger if less than the debounce time has elapsed since the last trigger
    if (elapsed_time < DEBOUNCE_TIME_MS) {
        return;
    }

    // Update the last ISR trigger time
    last_isr_time = current_time;

    // Process the ISR trigger
    std::cout << "Alert callback triggered: GPIO " << gpio << ", level " << level << std::endl;
}

int main(int argc, char *argv[]) {
    // Initialize pigpio library
    if (gpioInitialise() < 0) {
        std::cerr << "Unable to initialize GPIO" << std::endl;
        return 1;
    }

    // Set GPIO pin mode
    int gpio_pin = 16; // Example GPIO pin
    if (gpioSetMode(gpio_pin, PI_INPUT) != 0) {
        std::cerr << "Unable to set GPIO mode" << std::endl;
        gpioTerminate();
        return 1;
    }

    // Set alert function for falling edge
    if (gpioSetAlertFunc(gpio_pin, alertCallback) != 0) {
        std::cerr << "Failed to set alert function" << std::endl;
        gpioTerminate();
        return 1;
    }

    // Wait for input
    int exit;
    std::cin >> exit;

    // Clean up and terminate pigpio library
    gpioTerminate();
    return 0;
}
