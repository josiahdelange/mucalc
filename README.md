# Structured Singular Value ($`\mu`$) calculation
Interface to structured singular value (mu) computation

## Building and Installation
The Fortran module wrapper `library/mucalc.f90` exports subroutine `mucalc1` (which calls SLICOT's `AB13MD`) to C as `mucalc1_`.  These are compiled into a single library using CMake.
```
mkdir build
cd build
cmake -DSLICOT_DIR=<PATH_TO_SLICOT>/build/install/lib/cmake/SLICOT -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
ctest
```

## Tested Configurations
- Apple clang 13.0.0 / gfortran 11.2.0 / cmake 3.31.12 / SLICOT 5.9.1 / OpenBLAS 0.3.34

## References
[1] Fan, M. K., Tits, A. L., & Doyle, J. C. (1988, June). Robustness in the Presence of Joint Parametric Uncertainty and Unmodeled Dynamics. In 1988 American Control Conference (pp. 1195-1200). IEEE.

[2] P. Benner, V. Mehrmann, V. Sima, S. Van Huffel, and A. Varga, "SLICOT - A Subroutine Library in Systems and Control Theory", Applied and Computational Control, Signals, and Circuits (Birkhauser), Vol. 1, Ch. 10, pp. 505-546, 1999.

[3] S. Van Huffel, V. Sima, A. Varga, S. Hammarling, and F. Delebecque, "Development of High Performance Numerical Software for Control", IEEE Control Systems Magazine, Vol. 24, Nr. 1, Feb., pp. 60-76, 2004.

