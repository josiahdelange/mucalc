#include "mucalc.h"
#include <stdio.h>
#include <math.h>
#include <complex.h>

int main()
{
    double mu_result = 0.0;
    int info = -1;
    //
    // AB13MD EXAMPLE PROGRAM DATA
    //   6     5
    //   1     1     2     1     1
    //   1     1     2     2     2
    //   (-1.0,6.0)  (2.0,-3.0)  (3.0,8.0)
    //   (3.0,8.0)   (-5.0,-9.0) (-6.0,2.0)
    //   (4.0,2.0)   (-2.0,5.0)  (-6.0,-7.0)
    //   (-4.0,11.0) (8.0,-7.0)  (12.0,-1.0)
    //   (5.0,-4.0)  (-4.0,-8.0) (1.0,-3.0)
    //   (-6.0,14.0) (2.0,-5.0)  (4.0,16.0)
    //   (-1.0,6.0)  (2.0,-3.0)  (3.0,8.0)
    //   (3.0,8.0)   (-5.0,-9.0) (-6.0,2.0)
    //   (4.0,2.0)   (-2.0,5.0)  (-6.0,-7.0)
    //   (-4.0,11.0) (8.0,-7.0)  (12.0,-1.0)
    //   (5.0,-4.0)  (-4.0,-8.0) (1.0,-3.0)
    //   (-6.0,14.0) (2.0,-5.0)  (4.0,16.0)
    //
    //
    // AB13MD EXAMPLE PROGRAM RESULTS
    //
    // The value of the structured singular value is
    //
    // 0.4174753408D+02
    //
    const double mu_expected = 41.74753408;
    const int n = 6; // 6x6 matrix
    const int m = 5; // 5 uncertainty blocks
    const int nblock[5] = {1, 1, 2, 1, 1};
    const int itype[5] = {1, 1, 2, 2, 2};
    #if defined(_MSC_VER)
    const _Dcomplex Z[6][6] = {
        {_Cbuild(-1.0,6.0),
        _Cbuild(4.0,2.0),
        _Cbuild(5.0,-4.0),
        _Cbuild(-1.0,6.0),
        _Cbuild(4.0,2.0),
        _Cbuild(5.0,-4.0)},

        {_Cbuild(2.0,-3.0),
        _Cbuild(-2.0,5.0),
        _Cbuild(-4.0,-8.0),
        _Cbuild(2.0,-3.0),
        _Cbuild(-2.0,5.0),
        _Cbuild(-4.0,-8.0)},

        {_Cbuild(3.0,8.0),
        _Cbuild(-6.0,-7.0),
        _Cbuild(1.0,-3.0),
        _Cbuild(3.0,8.0),
        _Cbuild(-6.0,-7.0),
        _Cbuild(1.0,-3.0)},

        {_Cbuild(3.0,8.0),
        _Cbuild(-4.0,11.0),
        _Cbuild(-6.0,14.0),
        _Cbuild(3.0,8.0),
        _Cbuild(-4.0,11.0),
        _Cbuild(-6.0,14.0)},

        {_Cbuild(-5.0,-9.0),
        _Cbuild(8.0,-7.0),
        _Cbuild(2.0,-5.0),
        _Cbuild(-5.0,-9.0),
        _Cbuild(8.0,-7.0),
        _Cbuild(2.0,-5.0)},

        {_Cbuild(-6.0,2.0),
        _Cbuild(12.0,-1.0),
        _Cbuild(4.0,16.0),
        _Cbuild(-6.0,2.0),
        _Cbuild(12.0,-1.0),
        _Cbuild(4.0,16.0)},
    };
    #else
    const double _Complex Z[n][n] = {
        {CMPLX(-1.0,6.0),
        CMPLX(4.0,2.0),
        CMPLX(5.0,-4.0),
        CMPLX(-1.0,6.0),
        CMPLX(4.0,2.0),
        CMPLX(5.0,-4.0)},

        {CMPLX(2.0,-3.0),
        CMPLX(-2.0,5.0),
        CMPLX(-4.0,-8.0),
        CMPLX(2.0,-3.0),
        CMPLX(-2.0,5.0),
        CMPLX(-4.0,-8.0)},

        {CMPLX(3.0,8.0),
        CMPLX(-6.0,-7.0),
        CMPLX(1.0,-3.0),
        CMPLX(3.0,8.0),
        CMPLX(-6.0,-7.0),
        CMPLX(1.0,-3.0)},

        {CMPLX(3.0,8.0),
        CMPLX(-4.0,11.0),
        CMPLX(-6.0,14.0),
        CMPLX(3.0,8.0),
        CMPLX(-4.0,11.0),
        CMPLX(-6.0,14.0)},

        {CMPLX(-5.0,-9.0),
        CMPLX(8.0,-7.0),
        CMPLX(2.0,-5.0),
        CMPLX(-5.0,-9.0),
        CMPLX(8.0,-7.0),
        CMPLX(2.0,-5.0)},

        {CMPLX(-6.0,2.0),
        CMPLX(12.0,-1.0),
        CMPLX(4.0,16.0),
        CMPLX(-6.0,2.0),
        CMPLX(12.0,-1.0),
        CMPLX(4.0,16.0)},
    };
    #endif

    // Call SLICOT C interface wrapper
    mucalc1_(&Z[0][0], n, m, &nblock[0], &itype[0], &mu_result, &info);

    // Check result
    if(fabs(mu_result - mu_expected) < 1e-6)
    {
        printf("Test passed!  mu_result = %f\n", mu_result);
    }
    else
    {
        printf("Test failed!  mu_result = %f, info = %d\n", mu_result, info);
        return 1;
    }

    return 0;
}