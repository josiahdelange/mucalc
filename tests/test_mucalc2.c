#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include "mucalc.h"

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
    int n = 6; // 6x6 matrix
    int m = 5; // 5 uncertainty blocks
    int nblock[5] = {1, 1, 2, 1, 1};
    int itype[5] = {1, 1, 2, 2, 2};
    double _Complex (*Z)[n] = malloc(n*sizeof(*Z));

    Z[0][0] = CMPLX(-1.0,6.0);
    Z[0][1] = CMPLX(4.0,2.0);
    Z[0][2] = CMPLX(5.0,-4.0);
    Z[0][3] = CMPLX(-1.0,6.0);
    Z[0][4] = CMPLX(4.0,2.0);
    Z[0][5] = CMPLX(5.0,-4.0);

    Z[1][0] = CMPLX(2.0,-3.0);
    Z[1][1] = CMPLX(-2.0,5.0);
    Z[1][2] = CMPLX(-4.0,-8.0);
    Z[1][3] = CMPLX(2.0,-3.0);
    Z[1][4] = CMPLX(-2.0,5.0);
    Z[1][5] = CMPLX(-4.0,-8.0);

    Z[2][0] = CMPLX(3.0,8.0);
    Z[2][1] = CMPLX(-6.0,-7.0);
    Z[2][2] = CMPLX(1.0,-3.0);
    Z[2][3] = CMPLX(3.0,8.0);
    Z[2][4] = CMPLX(-6.0,-7.0);
    Z[2][5] = CMPLX(1.0,-3.0);

    Z[3][0] = CMPLX(3.0,8.0);
    Z[3][1] = CMPLX(-4.0,11.0);
    Z[3][2] = CMPLX(-6.0,14.0);
    Z[3][3] = CMPLX(3.0,8.0);
    Z[3][4] = CMPLX(-4.0,11.0);
    Z[3][5] = CMPLX(-6.0,14.0);

    Z[4][0] = CMPLX(-5.0,-9.0);
    Z[4][1] = CMPLX(8.0,-7.0);
    Z[4][2] = CMPLX(2.0,-5.0);
    Z[4][3] = CMPLX(-5.0,-9.0);
    Z[4][4] = CMPLX(8.0,-7.0);
    Z[4][5] = CMPLX(2.0,-5.0);

    Z[5][0] = CMPLX(-6.0,2.0);
    Z[5][1] = CMPLX(12.0,-1.0);
    Z[5][2] = CMPLX(4.0,16.0);
    Z[5][3] = CMPLX(-6.0,2.0);
    Z[5][4] = CMPLX(12.0,-1.0);
    Z[5][5] = CMPLX(4.0,16.0);

    // Call SLICOT C interface wrapper
    mucalc1_(&Z[0][0], &n, &m, &nblock[0], &itype[0], &mu_result, &info);

    // Check result
    if(fabs(mu_result - mu_expected) < 1e-6)
    {
        printf("Test passed!  mu_result = %f\n", mu_result);
        free(Z);
    }
    else
    {
        printf("Test failed!  mu_result = %f, info = %d\n", mu_result, info);
        free(Z);
        return 1;
    }

    return 0;
}