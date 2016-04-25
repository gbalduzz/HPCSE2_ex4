#pragma once
#include <array>
#include <complex>

using Complex = std::complex<double>;

struct Particles{
    std::array<Complex,N> z;
    std::array<double,N> w;
    };