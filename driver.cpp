#include "driver.hpp"

driver::driver(const std::string &filename)
    : m_filename(filename)
{
}

driver::~driver()
{
}

void driver::write(const std::string &value)
{
    std::ofstream ofs(m_filename, std::ios::out | std::ios::binary);
    ofs << value;
}

std::string driver::read()
{
    std::ifstream ifs(m_filename, std::ios::in | std::ios::binary);
    std::string data;
    std::getline(ifs, data);
    return (data);
}

