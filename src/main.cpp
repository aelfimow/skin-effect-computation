#include <iostream>
#include <cmath>
#include <stdexcept>

#include "formula.h"
#include "argv_parser.h"


int main(int argc, char *argv[])
try
{
    argv_parser ap { argc, argv };

    auto frequency = ap.frequency();
    auto sigma = ap.sigma();
    auto prefix = ap.prefix();
    auto mult_value = ap.frequency_factor(prefix);

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
