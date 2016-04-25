#ifndef PARTICLES_H
#define PARTICLES_H
#include <vector>
#include <complex>

using Complex = std::complex<double>;

struct Particles{
    std::vector<Complex> z;
    std::vector<double> w;
    Particles(int N):z(N),w(N){}
    };

#endif