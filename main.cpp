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
    int k=5;
    cout<<"\nExpansion order: "<<k<<endl;
    vector<Complex> c(k);
    {
        Profiler prof("P2E");
        c = P2E(p, k);
    }
    Complex z(1,1);
    double s=E2P(z,c);
    bool correct = check_from_file(s,k,"output.dat");
    if(correct) cout<<"Correct result!"<<endl;
}

