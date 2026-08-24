# Test from Fortran-90
add_executable(test_mucalc1 test_mucalc1.f90)
target_link_libraries(test_mucalc1 mucalc)
add_test(NAME test_mucalc1 COMMAND test_mucalc1)

# Test from C
add_executable(test_mucalc2 test_mucalc2.c)
target_include_directories(test_mucalc2 PUBLIC ${PROJECT_SOURCE_DIR}/library)
target_link_libraries(test_mucalc2 mucalc)
add_test(NAME test_mucalc2 COMMAND test_mucalc2)

# Test from C++
#add_executable(test_mucalc3 test_mucalc3.cpp)
#target_include_directories(test_mucalc3 PUBLIC ${PROJECT_SOURCE_DIR}/library)
#target_link_libraries(test_mucalc3 mucalc)
#add_test(NAME test_mucalc3 COMMAND test_mucalc3)
