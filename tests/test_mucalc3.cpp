#include <iostream>
#include <complex>
#include <vector>
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
    const int n = 6; // 6x6 matrix
    const int m = 5; // 5 uncertainty blocks
    const std::vector<int> nblock = {1, 1, 2, 1, 1};
    const std::vector<int> itype = {1, 1, 2, 2, 2};

    std::vector<std::complex<double>> Z = {
        {-1.0,6.0},
        {4.0,2.0},
        {5.0,-4.0},
        {-1.0,6.0},
        {4.0,2.0},
        {5.0,-4.0},

        {2.0,-3.0},
        {-2.0,5.0},
        {-4.0,-8.0},
        {2.0,-3.0},
        {-2.0,5.0},
        {-4.0,-8.0},

        {3.0,8.0},
        {-6.0,-7.0},
        {1.0,-3.0},
        {3.0,8.0},
        {-6.0,-7.0},
        {1.0,-3.0},

        {3.0,8.0},
        {-4.0,11.0},
        {-6.0,14.0},
        {3.0,8.0},
        {-4.0,11.0},
        {-6.0,14.0},

        {-5.0,-9.0},
        {8.0,-7.0},
        {2.0,-5.0},
        {-5.0,-9.0},
        {8.0,-7.0},
        {2.0,-5.0},

        {-6.0,2.0},
        {12.0,-1.0},
        {4.0,16.0},
        {-6.0,2.0},
        {12.0,-1.0},
        {4.0,16.0}
    };

    // Call SLICOT C interface wrapper
    mucalc1_(reinterpret_cast<double _Complex*>(Z.data()), n, m,
        nblock.data(), itype.data(), &mu_result, &info);

    // Check result
    if(std::abs(mu_result - mu_expected) < 1e-6)
    {
        std::cout << "Test passed!  mu_result = " << mu_result << '\n';
    }
    else
    {
        std::cout << "Test failed!  mu_result = " << mu_result;
        std::cout << ", info = " << info << '\n';
        return 1;
    }

    return 0;
}