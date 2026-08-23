# C-interface to SLICOT AB13MD subroutine
add_library(mucalc mucalc.f90)
target_link_libraries(mucalc PRIVATE SLICOT::slicot)
