# C-interface to SLICOT AB13MD subroutine
add_library(mucalc mucalc.f90)
target_link_libraries(mucalc PRIVATE SLICOT::slicot)
install(TARGETS mucalc DESTINATION library)
set_target_properties(mucalc PROPERTIES
    VERSION "${CPACK_VERSION_MAJOR}.${CPACK_VERSION_MINOR}.${CPACK_VERSION_PATCH}"
    SOVERSION "${CPACK_VERSION_MAJOR}")
