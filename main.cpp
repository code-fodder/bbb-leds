#include <iostream>
#include <thread>
#include <chrono>
#include "gpio_control.hpp"

int main()
{
    std::cout << "LEDs v1.3" << std::endl;

    // Setup LED 1 GPIO
    gpio_control gpio_cntl;
    gpio_cntl.init(gpio_pin::led_b, "out");
    gpio_cntl.init(gpio_pin::led_g, "out");
    gpio_cntl.init(gpio_pin::led_r, "out");

    // Main loop
    unsigned int sleep_time_ms = 1000;
    unsigned int divider = 10;
    unsigned int min_interval_ms = 100;
    while (true)
    {
#if 1
        static char colour = 1;
        switch (colour++ % 3)
        {
            case 0:
                gpio_cntl.set_value(gpio_pin::led_r, 1);
                gpio_cntl.set_value(gpio_pin::led_g, 0);
                gpio_cntl.set_value(gpio_pin::led_b, 0);
                break;
            case 1:
                gpio_cntl.set_value(gpio_pin::led_g, 1);
                gpio_cntl.set_value(gpio_pin::led_r, 0);
                gpio_cntl.set_value(gpio_pin::led_b, 0);
                break;
            case 2:
                gpio_cntl.set_value(gpio_pin::led_b, 1);
                gpio_cntl.set_value(gpio_pin::led_r, 0);
                gpio_cntl.set_value(gpio_pin::led_g, 0);
                break;
        }
#else
        // Just toggle one LED
        gpio_cntl.toggle(gpio_pin::led_b);
#endif
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
        sleep_time_ms = std::max(sleep_time_ms - (sleep_time_ms / divider), min_interval_ms);
    }

    return 0;
}
