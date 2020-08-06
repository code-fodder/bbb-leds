#include "gpio_control.hpp"
#include "driver.hpp"
#include <iostream>

static const std::string gpio_path = "/sys/class/gpio";
static const std::string gpio_export_path = gpio_path + "/export";
std::string pin_to_str(gpio_pin pin)    { return std::to_string(static_cast<unsigned int>(pin)); }
std::string pin_direction(gpio_pin pin) { return gpio_path + "/gpio" + std::to_string(static_cast<unsigned int>(pin)) + "/direction"; }
std::string pin_value(gpio_pin pin)     { return gpio_path + "/gpio" + std::to_string(static_cast<unsigned int>(pin)) + "/value"; }

void gpio_control::init(gpio_pin pin, const std::string &direction)
{
    std::cout << "Init GPIO_" << pin_to_str(pin) << " with direction " << direction << std::endl;
    driver export_drv(gpio_export_path);
    export_drv.write(pin_to_str(pin));
    set_direction(pin, direction);
}

void gpio_control::toggle(gpio_pin pin)
{
    // Read the value and toggle it between 1 and 0
    driver pin_drv(pin_value(pin));
    set_value(pin, 1 - std::stoi(pin_drv.read()));
}

void gpio_control::set_value(gpio_pin pin, int value)
{
    driver gpio_drv(pin_value(pin));
    gpio_drv.write(std::to_string(value));
}

void gpio_control::set_direction(gpio_pin pin, const std::string &direction)
{
    driver gpio_drv(pin_direction(pin));
    gpio_drv.write(direction);
}
