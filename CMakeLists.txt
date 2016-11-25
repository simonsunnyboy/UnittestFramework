#
# ASM Software Unittest Framework
# (c) 2016 by Matthias Arndt <marndt@asmsoftware.de>
#
# The MIT License applies. Check COPYING for details.
#
cmake_minimum_required(VERSION 2.8)
project(Unittest)

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Coverage CACHE STRING
       "Choose the type of build, options are: None Coverage Debug Release RelWithDebInfo MinSizeRel."
       FORCE )
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message("gcov enabled")
    add_definitions("-DGCOV_ENABLED")
endif()


# GNU coverage
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    message("coverage target created...")
    setup_target_for_coverage(example_unittest_coverage example_unittest coverage)
endif()

include_directories(
    src
    src/test_object
)

# the main library to link with project - projects should only use unittest.h and unittest.c
add_library(unittest
	src/unittest.c
	src/unittest.h
	README.md
	Doxyfile
    .gitignore
)

# an example test object with implemented unittest
add_executable(example_unittest
	src/test_object/test_object.c
	src/test_object/test_object.h
    src/test_object/example_unittest.c
)
target_link_libraries(example_unittest unittest -lgcov)


# generate Doxygen output
add_custom_target(Doxygen
    COMMAND doxygen ${PROJECT_SOURCE_DIR}/Doxyfile
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    DEPENDS ${PROJECT_SOURCE_DIR}/Doxyfile unittest example_unittest
)
