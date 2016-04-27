//
// Created by giovanni on 25.04.16.
//
#pragma once
#include "particles.h"
#include <complex>
#include <vector>
#include <cmath>




template<int k>
void P2E(const Particles& p,double* c_re,double* c_im){
    double z_re,z_im,z_temp; //will store (x+ i y) ^k
   for(int i=0;i<k+1;i++) c_re[i]=c_im[i]=0;

    for(int i=0;i<p.N;i++){
        c_re[0]+=p.w[i];
        z_re=1; z_im=0
                ;
        for(int j=1;j<k;j++){
            z_temp=z_re*p.x[i]-z_im*p.y[i];
            z_im=z_re*p.y[i]+z_im*p.x[i];
            z_re=z_temp;
            c_re[j]-=p.w[i]*z_re/j;
            c_im[j]-=p.w[i]*z_im/j;
        }
    }
}
