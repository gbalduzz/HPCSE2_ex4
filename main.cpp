const static int N=1e6;
const static int k=20;
#include <iostream>
#include "include/file_IO.h"
#include "include/particles.h"
#include "include/profiler.h"
#include "include/P2E.h"
#include "include/E2P.h"
using std::cout; using std::endl;


int main(int argc, char** argv) {
    Particles p(N);
    std::string filename="sources.bin";
    read_from_file(p,filename);
    cout<<"\nExpansion order: "<<k<<endl;
    double c_re[k+1],c_im[k+1];
    {
        Profiler prof("P2E");
        P2E<k>(p,c_re,c_im);
    }
    const double z_re=1,z_im=1;
    double s;
    {
        Profiler pr("E2P");
        s=E2P<k>(z_re,z_im,c_re,c_im);
    }
    bool correct = check_from_file(s,k,"output.dat");
    if(correct) cout<<"Correct result!"<<endl;
}

