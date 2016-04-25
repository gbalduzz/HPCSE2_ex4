#pragma once
#include "particles.h"
#include <cmath>

double E2P(Complex z,const std::vector<Complex>& a){ //a[0]=Q

    double result= (a[0]*std::log(z)).real();
    for(int k=1;k<a.size();k++) result+= (a[k]/std::pow(z,k)).real();
    return result;
}