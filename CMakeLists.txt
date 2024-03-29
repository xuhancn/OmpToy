cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(PROJ_NAME "OmpToy")
project (${PROJ_NAME})

set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH ${PROJECT_ROOT_DIR}/cmake/Modules)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

set(SOURCES_FILES ${PROJECT_ROOT_DIR}/src/main.cpp)
add_executable(${PROJ_NAME} ${SOURCES_FILES})

find_package(OMP QUIET)
if(${OpenMP_FOUND})
  # It will use openmp lib of current compiler.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  target_link_libraries(${PROJ_NAME} PUBLIC "${OpenMP_CXX_LIBRARIES}")
  target_link_libraries(${PROJ_NAME} PUBLIC "dl")
endif()