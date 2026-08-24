# Structured Singular Value Calculation
Wrapper interface to structured singular value ($`\mu`$) calculation provided by [SLICOT](https://github.com/SLICOT/SLICOT-Reference), using modern Fortran and the ISO C Bindings module.  Calls `AB13MD` to compute the upper bound of $`\mu_{\Delta}(Z)`$, where $`Z`$ is a complex $`(n \times n)`$ matrix and $`\Delta`$ is a block-structured uncertainty.  Basic unit tests reproduce the example problem in `TAB13MD` using modern Fortran, C and C++.

## Building and Installation
- Apple clang 13.0.0 / gfortran 11.2.0 / cmake 3.31.12 / SLICOT 5.9.1 / OpenBLAS 0.3.34
```
mkdir build
cd build
cmake -DSLICOT_DIR=<PATH_TO_SLICOT>/build/install/lib/cmake/SLICOT -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
ctest
```

- MSVC 19.44.35214.0 / ifx 2025.0.0 / cmake 3.31.6-msvc6 / SLICOT 5.9.1 / Intel MKL 2025.0
```
mkdir build
cd build
cmake -Tfortran=ifx -DSLICOT_DIR=<PATH_TO_SLICOT>/build/install/lib/cmake/SLICOT -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
ctest -C Release
```


## References
[1] Fan, M. K., Tits, A. L., & Doyle, J. C. (1988, June). Robustness in the Presence of Joint Parametric Uncertainty and Unmodeled Dynamics. In 1988 American Control Conference (pp. 1195-1200). IEEE.

[2] P. Benner, V. Mehrmann, V. Sima, S. Van Huffel, and A. Varga, "SLICOT - A Subroutine Library in Systems and Control Theory", Applied and Computational Control, Signals, and Circuits (Birkhauser), Vol. 1, Ch. 10, pp. 505-546, 1999.

[3] S. Van Huffel, V. Sima, A. Varga, S. Hammarling, and F. Delebecque, "Development of High Performance Numerical Software for Control", IEEE Control Systems Magazine, Vol. 24, Nr. 1, Feb., pp. 60-76, 2004.

