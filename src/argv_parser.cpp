#include <sstream>
#include <stdexcept>
#include <map>

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

double argv_parser::frequency_factor(std::string const &prefix) const
{
    std::map<std::string, double> supported_prefix
    {
        { "Hz", 1.0 },
        { "kHz", 1.0E3 },
        { "MHz", 1.0E6 },
        { "GHz", 1.0E9 },
        { "THz", 1.0E12 }
    };

    auto it { supported_prefix.find(prefix) };

    if (it == supported_prefix.end())
    {
        throw std::runtime_error("Unsupported prefix: " + prefix);
    }

    auto const value { it->second };

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
