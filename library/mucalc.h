#ifndef MUCALC_H
#define MUCALC_H

#ifdef __cplusplus
extern "C" {
#endif

// SLICOT AB13MD C interface wrapper
#if defined(_WIN32)
    //#define _CRT_SECURE_NO_WARNINGS
    //#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
    //#ifdef __cplusplus
    //#include <complex>
    //#else
    //#include <complex.h>
    //#endif
    #include <complex.h>
    void mucalc1_(const _Dcomplex* Z, const int n, const int m,
        const int* nblock, const int* itype, double* bound, int* info);

#elif defined(__APPLE__)
    #include <complex.h>
    void mucalc1_(const double _Complex* Z, const int n, const int m,
        const int* nblock, const int* itype, double* bound, int* info);

#elif defined(__linux__)
    #include <complex.h>
    void mucalc1_(const double _Complex* Z, const int n, const int m,
        const int* nblock, const int* itype, double* bound, int* info);

#else
#error "Unknown or unsupported operating system"
#endif

#ifdef __cplusplus
}
#endif

#endif ///MUCALC_H