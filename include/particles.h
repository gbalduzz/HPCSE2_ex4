#ifndef PARTICLES_H
#define PARTICLES_H
#include <vector>

using Complex = std::complex<double>;

struct Particle{
    double w,x,y;
};

using Particles=std::vector<Particle>;

#endif