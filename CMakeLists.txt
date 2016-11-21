#
# ASM Software Unittest Framework
# (c) 2016 by Matthias Arndt <marndt@asmsoftware.de>
#
# The MIT License applies. Check COPYING for details.
#
cmake_minimum_required(VERSION 2.8)
project(Unittest)

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug CACHE STRING
       "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
       FORCE )
endif()

include_directories(
    src
    src/test_object
)

# the main library to link with project - projects should only use unittest.h
add_library(unittest
	src/unittest.c
	src/unittest.h
	README.md
	Doxyfile
)

# an example test object with implemented unittest
add_executable(test_object
	src/test_object/test_object.c
	src/test_object/test_object.h
)
target_link_libraries(test_object unittest)

