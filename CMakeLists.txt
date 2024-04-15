# ===== Project Setup =====
cmake_minimum_required(VERSION 3.20.0)
project(SPHLUID VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ===== TPL ======

# Kokkos
add_subdirectory(kokkos)
#find_package(Kokkos REQUIRED)

# ===== Sources =====
add_subdirectory(src)
