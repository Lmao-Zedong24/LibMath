
# set project
get_filename_component(CURRENT_FOLDER_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(PROJECT_NAME ${CURRENT_FOLDER_NAME})


###############################
#                             #
# Sources                     #
#                             #
###############################

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/*.cc # C with classe
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.cxx
	${CMAKE_CURRENT_SOURCE_DIR}/*.c++)
	
# Add header files
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Header)
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.inl)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PROJECT_FILES})


###############################
#                             #
# Catch2                      #
#                             #
###############################

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)



###############################
#                             #
# GLM                         #
#                             #
###############################

FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG		   0.9.9.8
)

FetchContent_GetProperties(glm)
if(NOT glm_POPULATED)
	FetchContent_Populate(glm)
	set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
	add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
endif()


###############################
#                             #
# Executable                  #
#                             #
###############################

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
include_directories(${PROJECT_INCLUDE_DIR} ${LIBMATH_INCLUDE_DIR} ${glm_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}
    PRIVATE
	${LIBMATH_NAME}
	Catch2::Catch2)
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /Za)
  # /Za disable compiler language extension (https://github.com/g-truc/glm/blob/master/doc/manual.pdf page 44)
  target_link_options(${PROJECT_NAME} PRIVATE /FORCE:UNRESOLVED)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# ??? auto run all test on cmake build ??? # todo test
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
#include(CTest)
#include(Catch)
#catch_discover_tests(${PROJECT_NAME})