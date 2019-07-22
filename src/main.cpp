#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <map>

#include "formula.h"


int main(int argc, char *argv[])
try
{
    if (argc != 4)
    {
        throw std::invalid_argument("Usage: frequency prefix sigma");
    }

    constexpr double zero { 0.0 };

    auto frequency { zero };
    {
        std::stringstream ss { argv[1] };
        ss >> frequency;
    }

    std::string prefix;
    {
        std::stringstream ss { argv[2] };
        ss >> prefix;
    }

    auto sigma { zero };
    {
        std::stringstream ss { argv[3] };
        ss >> sigma;
    }

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

    auto const mult_value { it->second };

    std::cout << "Frequency: " << frequency << " " << prefix << std::endl;
    std::cout << "Sigma: " << sigma << std::endl;

    formula::param_set1 const param_set { frequency * mult_value, sigma };

    formula func { param_set };

    std::cout << "Delta: " << func.delta() << " m" << std::endl;

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
