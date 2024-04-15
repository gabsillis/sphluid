# src

# sph functionality
add_library(sphluid_sph sph.cxx)
target_sources(sphluid_sph
    PUBLIC
    FILE_SET HEADERS FILES 
    include/sph.hpp)
target_link_libraries(sphluid_sph PUBLIC Kokkos::kokkos)
target_include_directories(sphluid_sph PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# main executable
add_executable(sphluid sphluid.cxx)
target_link_libraries(sphluid sphluid_sph)
