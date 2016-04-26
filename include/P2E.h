//
// Created by giovanni on 25.04.16.
//
#pragma once
#include "particles.h"
#include <vector>
#include <complex>
#include <cmath>
using std::vector;
using complex = std::complex<double>;

vector<complex> P2E(const Particles& p,const int k){
    vector<complex> coeff(k+1,0);
for(int i=0;i<N;i++){
    coeff[0]+=p.w[i];
    for(int j=1;j<=k;j++) coeff[j]-=p.w[i]*std::pow(Complex(p.x[i],p.y[i]),j)/complex(j,0);
}
    return coeff;
}

