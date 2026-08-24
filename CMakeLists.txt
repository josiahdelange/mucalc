cmake_minimum_required(VERSION 3.10)
project(mucalc)

# Version number
set(CPACK_VERSION_MAJOR 1)
set(CPACK_VERSION_MINOR 0)
set(CPACK_VERSION_PATCH 0)

# Git version
find_package(Git QUIET)
execute_process(
    # Git branch name at compile time
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
    OUTPUT_VARIABLE GIT_BRANCH_NAME
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE GIT_RESULT
)
execute_process(
    # Latest Git commit at compile time
    COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
    OUTPUT_VARIABLE GIT_LAST_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE GIT_RESULT
)
execute_process(
    # Whether there are uncommitted changes at compile time
    COMMAND ${GIT_EXECUTABLE} describe --dirty --always
    OUTPUT_VARIABLE GIT_DESCRIBE_STRING
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE GIT_RESULT
)
if(GIT_DESCRIBE_STRING MATCHES "dirty")
    set(GIT_DIRTY_BUILD true)
else()
    set(GIT_DIRTY_BUILD true)
endif()

# Version string
if(GIT_DIRTY_BUILD)
    set(VERSION_STRING
        "v${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}-dev")
else()
    set(VERSION_STRING
        "v${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
endif()

enable_testing()
enable_language(C)
enable_language(CXX)
enable_language(Fortran)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Debug, Release, RelWithDebInfo, MinSizeRel" FORCE)
endif()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Install prefix" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

option(BUILD_SHARED_LINS "Build using shared libraries" ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} CACHE
    PATH "Directory where all the .lib files are dumped" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} CACHE
    PATH "Directory where all the .exe and .dll files are dumped" FORCE)
set(CMAKE_Fortran_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/modules)

# SLICOT library for control theory subroutines
find_package(SLICOT REQUIRED)

message("-- Building project out of " ${PROJECT_SOURCE_DIR})
message("-- Build type: " ${CMAKE_BUILD_TYPE})
message("-- Build directory: " ${CMAKE_BINARY_DIR})
message("-- Install directory: " ${CMAKE_INSTALL_PREFIX})

# Compiler flags
if(WIN32)
    # Microsoft Windows
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -nologo")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -Qm64")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fpp")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -traceback")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -check:none")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -libs:dll")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -threads")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
elseif(APPLE)
    # Apple OS X
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -std=legacy")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -m64")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -finit-local-zero")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -O3")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -Wno-line-truncation")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -cpp")
elseif(UNIX)
    # Linux and other Unix-like OS
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -std=legacy")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -m64")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -finit-local-zero")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -O3")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -Wno-line-truncation")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -cpp")
endif()

# Library interface to SLICOT AB13MD
add_subdirectory(library)

# Unit tests
add_subdirectory(tests)

# Packaging a build
set(CPACK_GENERATOR "TGZ") # tarball
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_STRING}")
include(CPack)
