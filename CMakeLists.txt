
cmake_minimum_required (VERSION 3.5)
project(smurfs)

# include
include_directories(./include)
# find config.h
include_directories("${PROJECT_BINARY_DIR}")

# debug
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# sub dir
add_subdirectory(utils)
add_subdirectory(sort)
add_subdirectory(algo)

# intall dir
SET(CMAKE_INSTALL_PREFIX /usr/local/smurfs)

# version number
set(Smurfs_VERSION_MAJOR 1)
set(Smurfs_VERSION_MINOR 0)

# configure a header file to pass some of CMake settings to source file
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# should we enable smurfs test?
# ccmake ../  
# cmake-gui ../
option(SMURFS_TEST "Enable smurfs test." ON)

# if enable test library?
if (SMURFS_TEST)
    add_subdirectory(./test)
    #-------------------------------test------------------------------------
    # enable test
    enable_testing()
    # take care path test/ not ./
    macro(do_test arg result)
        add_test(test_${arg} test/smurfs_test)
        set_tests_properties(test_${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
    endmacro(do_test)

    do_test (2 "[1 2 3 5 4]")
endif (SMURFS_TEST)

# install
install (FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)
