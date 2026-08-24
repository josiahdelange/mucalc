#ifndef MUCALC_H
#define MUCALC_H

#ifdef __cplusplus
extern "C" {
#endif

// SLICOT AB13MD C interface wrapper
#include <complex.h>
void mucalc1_(const double _Complex* Z, const int* n, const int* m,
    const int* nblock, const int* itype, double* bound, int* info);

#ifdef __cplusplus
}
#endif

#endif ///MUCALC_H