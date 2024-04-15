#include "Kokkos_Core.hpp"
#include "sph.hpp"
using namespace sphluid;
int main(int argc, char *argv[]){
    Kokkos::initialize(argc, argv);

    Kokkos::finalize();
    return 0;
}
