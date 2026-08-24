module mucalc
    implicit none

contains
    subroutine mucalc1(Z, n, m, nblock, itype, bound, info) bind(C, name = "mucalc1_")
        use, intrinsic :: iso_c_binding

        complex(c_double_complex), intent(in) :: Z(n,n)
        integer(c_int), intent(in), value :: n
        integer(c_int), intent(in), value :: m
        integer(c_int), intent(in) :: nblock(m)
        integer(c_int), intent(in) :: itype(m)
        real(c_double), intent(out) :: bound
        integer(c_int), intent(out) :: info

        integer(c_int) :: ldwork, lzwork, liwork, ldz
        integer(c_int), allocatable :: iwork(:)
        real(c_double), allocatable :: dwork(:)
        complex(c_double_complex), allocatable :: zwork(:)
        real(c_double), allocatable :: X(:)
        real(c_double), allocatable :: D(:)
        real(c_double), allocatable :: G(:)
        integer :: ii, jj

        ! Allocate work vectors
        ldz = max(1, n)
        liwork = max(4*m - 2, n)
        ldwork = 2*n*n*m - n*n + 9*m*m + n*m + 11*n + 33*m - 11
        lzwork = 6*n*n*m + 12*n*n + 6*m + 6*n - 3

        write(*,*) "ldz = ", ldz
        write(*,*) "liwork = ", liwork
        write(*,*) "ldwork = ", ldwork
        write(*,*) "n = ", n
        write(*,*) "m = ", m

        allocate(iwork(liwork), dwork(ldwork), zwork(lzwork))
        allocate(X(2*m), D(n), G(n))

        write(*,*) "Z = "
        do ii = 1,n
            do jj = 1,n
                write(*,*) Z(ii,jj)
            end do
        end do


        ! Call SLICOT subroutine from Fortran-90 module
        write(*,*) "Calling AB13MD"
        call AB13MD('N', n, Z, ldz, m, nblock, itype, X, bound, D, G, &
        &   iwork, dwork, ldwork, zwork, lzwork, info)

        deallocate(iwork, dwork, zwork, X, D, G)

    end subroutine mucalc1

end module mucalc