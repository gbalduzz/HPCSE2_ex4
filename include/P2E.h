//
// Created by giovanni on 25.04.16.
//
#pragma once
#include "particles.h"
#include <complex>
#include <vector>
#include <cmath>
using std::vector;
using Complex = std::complex<double>;

template<int k>
inline void sum_kth_coeff(vector<Complex>& c,const Particles& p, const int i){
    c[k]-=p.w[i]*std::pow(Complex(p.x[i],p.y[i]),k)/Complex(k,0);
    sum_kth_coeff<k-1>(c,p,i);
}

template<>
inline void sum_kth_coeff<0>(vector<Complex>& c,const Particles& p, const int i){
    c[0]+=p.w[i];
}

template <int k>
vector<Complex> P2E(const Particles& p){
    vector<Complex> coeff(k+1,0);
    for(int i=0;i<p.N;i++){
        sum_kth_coeff<k>(coeff,p,i);
    }
    return coeff;
}
