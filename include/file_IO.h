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
    std::vector<double> x(N),y(N),w(N);
    const int size=N*sizeof(double);
    inp.read((char*)x.data(),size);
    inp.read((char*)y.data(),size);
    inp.read((char*)w.data(),size);
    for(int i=0;i<N;i++){
        p[i].x=x[i];
        p[i].y=y[i];
        p[i].w=w[i];
    }
    inp.close();
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
    bool check =  std::abs((ref-res)/ref) < 1e-6;
    if(not check)
    {
        cout.precision(15);
        cout<<"Computation error"<<endl;
        cout<<"Stream:\t"<<res<<endl;
        cout<<"File value:\t"<<ref<<endl;
    }
    return check;
}