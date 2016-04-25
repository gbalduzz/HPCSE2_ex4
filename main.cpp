const static int N=1e6;
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
    int k=5;
    if(argc>1) k=std::atoi(argv[1]);
    vector<Complex> c(k);
    {
        Profiler prof("P2E");
        c = P2E(p, k);
    }
    cout<<"\nExpansion order: "<<k<<endl;
    Complex z(10,10);
    double s=E2P(z,c);
    cout<<"\nStream: "<<s<<endl;
    cout<<"coeff:"<<endl;
    for(int i=0;i<c.size();i++) cout<<c[i]<<endl;
}

