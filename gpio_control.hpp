#include <string>

enum class gpio_pin : unsigned int
{
    led_1 = 68,
    led_r = 44,
    led_g = 68,
    led_b = 67
};

class gpio_control
{
public:
    void init(gpio_pin pin, const std::string &direction = "out");
    void toggle(gpio_pin pin);
    void set_value(gpio_pin pin, int value);
    void set_direction(gpio_pin pin, const std::string &direction);
};

