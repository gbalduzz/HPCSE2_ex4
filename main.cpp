const static int N=1e6;
const static int k=20;
#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include "include/file_IO.h"
#include "include/particles.h"
#include "include/profiler.h"
#include "include/P2E.h"
#include "include/E2P.h"
using std::cout; using std::endl;
using std::vector;


int main(int argc, char** argv) {
    Particles p(N);
    std::string filename="sources.bin";
    read_from_file(p,filename);
    cout<<"\nExpansion order: "<<k<<endl;
    double c_re[k+1],c_im[k+1];
    {
        Profiler prof("P2E");
        P2E(p,k,c_re,c_im);
    }
    Complex z(1,1);
    vector<Complex> c(k+1);
    for(int i=0;i<k+1;i++) c[i]=Complex(c_re[i],c_im[i]);
    double s=E2P(z,c);
    bool correct = check_from_file(s,k,"output.dat");
    if(correct) cout<<"Correct result!"<<endl;
}

