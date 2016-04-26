#pragma once
#include <complex>
#include <string>
#include <cmath>
#include <fstream>
#include <assert.h>
#include "particles.h"

void read_from_file(Particles& p, const std::string& filename){
    std::ifstream inp(filename.c_str(),std::ios::binary);
    assert(inp);
    const int size=N*sizeof(double);
    char *char_x=new char [size];
    char* char_y=new char [size];
    char* char_w=new char[size];
    inp.read(char_x,size);
    double *x=(double*) char_x;
    inp.read(char_y,size);
    double *y=(double*) char_y;
    inp.read(char_w,size);
    double *w=(double*) char_w;
    for(int i=0;i<N;i++){
        p.z[i]=std::complex<double>(x[i],y[i]);
        p.w[i]=w[i];
    }
    inp.close();
    delete[] char_w;
    delete[] char_x;
    delete[] char_y;

}

#include <iostream>
using std::cout; using std::endl;
bool check_from_file(double res,int k, const std::string& filename){
    std::ifstream inp(filename.c_str());
    assert(inp);
    std::string line;
    for(int i=0;i<k;i++) std::getline(inp,line);
    double ref;
    inp>>ref>>ref;
    inp.close();
    bool check =  std::abs(ref-res) < 1e-3;
    if(not check)
    {
        cout.precision(15);
        cout<<"Computation error"<<endl;
        cout<<"Stream:\t"<<res<<endl;
        cout<<"File value:\t"<<ref<<endl;
    }
    return check;
}