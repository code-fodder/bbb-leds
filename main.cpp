#include <iostream>
#include <thread>
#include <chrono>
#include "gpio_control.hpp"

int main()
{
    std::cout << "LEDs v1.2" << std::endl;

    // Setup LED 1 GPIO
    gpio_control gpio_cntl;
    gpio_cntl.init(gpio_pin::led_1, "out");

    // Main loop
    unsigned int sleep_time_ms = 1000;
    unsigned int divider = 10;
    unsigned int min_interval_ms = 20;
    while (true)
    {
        gpio_cntl.toggle(gpio_pin::led_1);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
        sleep_time_ms = std::max(sleep_time_ms - (sleep_time_ms / divider), min_interval_ms);
    }

    return 0;
}
