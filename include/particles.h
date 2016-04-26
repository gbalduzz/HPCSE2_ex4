#ifndef PARTICLES_H
#define PARTICLES_H
#include <vector>
#include <complex>

using Complex = std::complex<double>;

struct Particles{
    std::vector<double> w,x,y;
    Particles(int N):x(N),y(N),w(N){}
    };

#endif