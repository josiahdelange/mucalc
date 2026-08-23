module mucalc
    implicit none

contains
    subroutine slicot_ab13md(fact, n, z, ldz, m, nblock, itype, x, bound, d, g, &
        &   iwork, dwork, ldwork, zwork, lzwork, info) bind(C, name="slicot_ab13md_")
        use, intrinsic :: iso_c_binding

        character(c_char), intent(in) :: fact
        integer(c_int), intent(in) :: n
        complex(c_double_complex), intent(in) :: z(ldz, *)
        integer(c_int), intent(in) :: ldz
        integer(c_int), intent(in) :: m
        integer(c_int), intent(in) :: nblock(*)
        integer(c_int), intent(in) :: itype(*)
        real(c_double), intent(inout) :: x(*)
        real(c_double), intent(out) :: bound
        real(c_double), intent(out) :: d(*)
        real(c_double), intent(out) :: g(*)
        integer(c_int), intent(inout) :: iwork(*)
        real(c_double), intent(inout) :: dwork(*)
        integer(c_int), intent(in) :: ldwork
        complex(c_double_complex), intent(inout) :: zwork(*)
        integer(c_int), intent(in) :: lzwork
        integer(c_int), intent(out) :: info

        ! Call SLICOT subroutine from Fortran-90 module
        call AB13MD(fact, n, z, ldz, m, nblock, itype, x, bound, d, g, &
        &   iwork, dwork, ldwork, zwork, lzwork, info)
    end subroutine slicot_ab13md
end module mucalc