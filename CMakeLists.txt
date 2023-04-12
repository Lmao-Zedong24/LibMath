cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_UNIT_TEST "Build unit test with catch2" ON)

# set solution
project(LibMath LANGUAGES CXX)

add_subdirectory(LibMath)

if (${BUILD_UNIT_TEST})
	add_subdirectory(LibMath_UnitTest)

	if(MSVC)
	  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT LibMath_UnitTest)
	endif()
endif()