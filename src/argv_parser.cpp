#include <sstream>
#include <stdexcept>

#include "argv_parser.h"


argv_parser::argv_parser(int argc, char *argv[]) :
    m_argv { }
{
    for (auto i = 0; i < argc; ++i)
    {
        m_argv.push_back(argv[i]);
    }

    if (4 != m_argv.size())
    {
        throw std::invalid_argument("Usage: frequency prefix sigma");
    }
}

argv_parser::~argv_parser()
{
}

double argv_parser::frequency() const
{
    double value { };
    std::stringstream ss { m_argv[1] };
    ss >> value;
    return value;
}

std::string argv_parser::prefix() const
{
    std::string str;
    std::stringstream ss { m_argv[2] };
    ss >> str;
    return str;
}

double argv_parser::sigma() const
{
    double value { };
    std::stringstream ss { m_argv[3] };
    ss >> value;
    return value;
}
