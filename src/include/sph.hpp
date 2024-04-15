#pragma once
#include <array>
#include "Kokkos_Core.hpp"
namespace sphluid {

    /**
     * @brief a box that bounds a region in space 
     */
    struct BoundingBox{
        static constexpr int ndim = 2;
        std::array<double, ndim> xmin = {0.0, 0.0};
        std::array<double, ndim> xmax = {1.0, 1.0};

        /**
         * @brief get the length in a given dimension 
         * @param dimension the index of the dimension 
         * x - 0 
         * y - 1 
         */
        inline constexpr
        auto length(int dimension) const noexcept -> double {
            return xmax[dimension] - xmin[dimension];
        }

        /// @brief get the length in the x dimension
        inline constexpr 
        auto xlen() const noexcept -> double {
            return length(0);
        }

        /// @brief get the length in the y dimension
        inline constexpr 
        auto ylen() const noexcept -> double {
            return length(1);
        }
    };

    /**
     * @brief a description of a box shaped domain 
     */
    struct box_domain {
        BoundingBox bounds;
    };

    /**
     * @brief the particle data for the simulation
     * holds the position, velocity, and acceleration data 
     */
    class sph_particles {
        private:
        static constexpr int ndim = 2;
        Kokkos::View<double*[ndim], Kokkos::DefaultExecutionSpace::memory_space> positions;
        Kokkos::View<double*[ndim], Kokkos::DefaultExecutionSpace::memory_space> velocities;
        Kokkos::View<double*[ndim], Kokkos::DefaultExecutionSpace::memory_space> accelerations;

        public:
        auto spawn_particles_square(int nx, int ny, BoundingBox bounds) -> void {
            double dx = bounds.xlen() / (nx - 1);
            double dy = bounds.ylen() / (ny - 1);
            
        }
    };
}
