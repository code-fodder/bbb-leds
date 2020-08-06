
#include <string>
#include <fstream>

class driver
{
public:
    explicit driver(const std::string &filename);
    ~driver();

    void write(const std::string &value);
    std::string read();

private:
    std::string m_filename;
};
