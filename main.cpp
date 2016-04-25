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


int main() {
    Particles p(N);
    std::string filename="sources.bin";
    read_from_file(p,filename);
    const int k=5;
    vector<complex> c=P2E(p,k);

    for(int i=0;i<c.size();i++) cout<<c[i]<<endl;
}

