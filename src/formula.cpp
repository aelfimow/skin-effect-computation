#include <cmath>

#include "formula.h"

constexpr double pi = std::acos(-1.0);
constexpr double mu = 4.0 * pi * 1.0E-7;

formula::formula(param_set1 const &param) :
    m_freq { param.freq },
    m_sigma { param.sigma },
    m_delta { std::sqrt(2.0 / (2.0 * pi * param.freq * mu * param.sigma)) }
{
}

formula::~formula()
{
}

double formula::frequency() const
{
    return m_freq;
}

double formula::sigma() const
{
    return m_sigma;
}

double formula::delta() const
{
    return m_delta;
}
