! Test program for AB13MD interface
program test_mucalc1
    use, intrinsic :: iso_c_binding
    use mucalc
    implicit none

    real(c_double) :: mu_result
    integer(c_int) :: info
    !
    ! AB13MD EXAMPLE PROGRAM DATA
    !   6     5
    !   1     1     2     1     1
    !   1     1     2     2     2
    !   (-1.0D0,6.0D0)  (2.0D0,-3.0D0)  (3.0D0,8.0D0)
    !   (3.0D0,8.0D0)   (-5.0D0,-9.0D0) (-6.0D0,2.0D0)
    !   (4.0D0,2.0D0)   (-2.0D0,5.0D0)  (-6.0D0,-7.0D0)
    !   (-4.0D0,11.0D0) (8.0D0,-7.0D0)  (12.0D0,-1.0D0)
    !   (5.0D0,-4.0D0)  (-4.0D0,-8.0D0) (1.0D0,-3.0D0)
    !   (-6.0D0,14.0D0) (2.0D0,-5.0D0)  (4.0D0,16.0D0)
    !   (-1.0D0,6.0D0)  (2.0D0,-3.0D0)  (3.0D0,8.0D0)
    !   (3.0D0,8.0D0)   (-5.0D0,-9.0D0) (-6.0D0,2.0D0)
    !   (4.0D0,2.0D0)   (-2.0D0,5.0D0)  (-6.0D0,-7.0D0)
    !   (-4.0D0,11.0D0) (8.0D0,-7.0D0)  (12.0D0,-1.0D0)
    !   (5.0D0,-4.0D0)  (-4.0D0,-8.0D0) (1.0D0,-3.0D0)
    !   (-6.0D0,14.0D0) (2.0D0,-5.0D0)  (4.0D0,16.0D0)
    !
    !
    ! AB13MD EXAMPLE PROGRAM RESULTS
    !
    ! The value of the structured singular value is
    !
    ! 0.4174753408D+02
    !
    real(c_double), parameter :: mu_expected = 0.4174753408D+02
    integer(c_int), parameter :: n = 6 ! 6x6 matrix
    integer(c_int), parameter :: m = 5 ! 5 uncertainty blocks
    integer(c_int), dimension(m) :: nblock = (/ 1, 1, 2, 1, 1 /)
    integer(c_int), dimension(m) :: itype = (/ 1, 1, 2, 2, 2 /)
    complex(c_double_complex) :: Z(n,n)
    Z(1,1) = (-1.0D0,6.0D0)
    Z(1,2) = (2.0D0,-3.0D0)
    Z(1,3) = (3.0D0,8.0D0)
    Z(1,4) = (3.0D0,8.0D0)
    Z(1,5) = (-5.0D0,-9.0D0)
    Z(1,6) = (-6.0D0,2.0D0)
    Z(2,1) = (4.0D0,2.0D0)
    Z(2,2) = (-2.0D0,5.0D0)
    Z(2,3) = (-6.0D0,-7.0D0)
    Z(2,4) = (-4.0D0,11.0D0)
    Z(2,5) = (8.0D0,-7.0D0)
    Z(2,6) = (12.0D0,-1.0D0)
    Z(3,1) = (5.0D0,-4.0D0)
    Z(3,2) = (-4.0D0,-8.0D0)
    Z(3,3) = (1.0D0,-3.0D0)
    Z(3,4) = (-6.0D0,14.0D0)
    Z(3,5) = (2.0D0,-5.0D0)
    Z(3,6) = (4.0D0,16.0D0)
    Z(4,1) = (-1.0D0,6.0D0)
    Z(4,2) = (2.0D0,-3.0D0)
    Z(4,3) = (3.0D0,8.0D0)
    Z(4,4) = (3.0D0,8.0D0)
    Z(4,5) = (-5.0D0,-9.0D0)
    Z(4,6) = (-6.0D0,2.0D0)
    Z(5,1) = (4.0D0,2.0D0)
    Z(5,2) = (-2.0D0,5.0D0)
    Z(5,3) = (-6.0D0,-7.0D0)
    Z(5,4) = (-4.0D0,11.0D0)
    Z(5,5) = (8.0D0,-7.0D0)
    Z(5,6) = (12.0D0,-1.0D0)
    Z(6,1) = (5.0D0,-4.0D0)
    Z(6,2) = (-4.0D0,-8.0D0)
    Z(6,3) = (1.0D0,-3.0D0)
    Z(6,4) = (-6.0D0,14.0D0)
    Z(6,5) = (2.0D0,-5.0D0)
    Z(6,6) = (4.0D0,16.0D0)

    ! Call SLICOT C interface wrapper
    mu_result = 0.0
    info = -1
    call mucalc1(Z, n, m, nblock, itype, mu_result, info)

    ! Check result
    if(abs(mu_result - mu_expected) < 1e-6) then
        write(*,*) 'Test passed!  mu_result = ', mu_result
    else
        write(*,*) 'Test failed!  mu_result = ', mu_result
        stop 1
    end if
end program test_mucalc1
