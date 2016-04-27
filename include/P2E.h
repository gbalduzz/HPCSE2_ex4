//
// Created by giovanni on 25.04.16.
//
#pragma once
#include "particles.h"
#include <complex>
#include <vector>
#include <cmath>





void P2E(const Particles& p, const int k,double* c_re,double* c_im){
    double z_re,z_im; //will store (x+ i y) ^k
   for(int i=0;i<k+1;i++) c_re[i]=c_im[i]=0;

    for(int i=0;i<p.N;i++){
        c_re[0]+=p.w[i];
        z_re=1; z_im=0;
        for(int j=1;j<k;j++){
            z_re=z_re*p.x[i]-z_im*p.y[i];
            z_im=z_re*p.y[i]+z_im*p.x[i];
            c_re[j]-=p.w[i]*z_re/j;
            c_im[j]-=p.w[i]*z_im/j;
        }
    }
}
