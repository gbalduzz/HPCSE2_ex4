//
// Created by giovanni on 25.04.16.
//
#pragma once
#include "particles.h"
#include <complex>
#include <cmath>

template<int k,int K>
struct sum_kth_coeff{
        inline static void execute (double* c_re,double* c_im,
                                    const double x,const double y,const double w,double z_re,double z_im){
            //compute z=(x+i y)^k
            z_re=z_re*x-z_im*y;
            z_im=z_re*y+z_im*x;

            c_re[k]-=w*z_re/k;
            c_im[k]-=w*z_im/k;
            sum_kth_coeff<k+1,K>::execute(c_re,c_im,x,y,w,z_re,z_im);
        }
};

template<int k>
struct sum_kth_coeff<k,k>{
    inline static void execute (double* c_re,double* c_im,
                                const double x,const double y,const double w,double z_re,double z_im){
        //compute z=(x+i y)^k
        z_re=z_re*x-z_im*y;
        z_im=z_re*y+z_im*x;

        c_re[k]-=w*z_re/k;
        c_im[k]-=w*z_im/k;
    }//end recursion
};

template <int k>
void P2E(const Particles& p, double* c_re,double* c_im){ //c_re and c_im must have k+1 reserved spaces
   for(int i=0;i<k+1;i++) c_re[i]=c_im[i]=0;

    for(int i=0;i<p.N;i++){
        c_re[0]+=p.w[i];
        sum_kth_coeff<1,k>::execute(c_re,c_im,p.x[i],p.y[i],p.w[i],1.,0.);
    }

}
