cmake_minimum_required(VERSION 3.14)
project(CMakeDemo)
set(CMAKE_CXX_STANDARD 17)

option(${PROJECT_NAME}_ENABLE_MPI "Enable MPI-based parallel computating." "ON")
if (${PROJECT_NAME}_ENABLE_MPI)
  find_path(MPI_INC NAMES "mpi.h")
  find_library(MPI_LIB NAMES mpi)
endif (${PROJECT_NAME}_ENABLE_MPI)
message("mpi INC : ${MPI_INC}")
message("mpi LIB : ${MPI_LIB}")

if (${PROJECT_NAME}_ENABLE_MPI)
  find_path(CGNS_INC "pcgnslib.h" HINTS ENV CGNS_ROOT PATH_SUFFIXES include)
else (${PROJECT_NAME}_ENABLE_MPI)
  find_path(CGNS_INC "cgnslib.h" HINTS ENV CGNS_ROOT PATH_SUFFIXES include)
endif (${PROJECT_NAME}_ENABLE_MPI)
find_library(CGNS_LIB cgns HINTS ENV CGNS_ROOT PATH_SUFFIXES lib)
message("cgns INC : ${CGNS_INC}")
message("cgns LIB : ${CGNS_LIB}")

find_path(PETSC_INC "petsc.h")
find_library(PETSC_LIB petsc HINTS ENV PETSC_ROOT PATH_SUFFIXES lib)
message("petsc INC : ${PETSC_INC}")
message("petsc LIB : ${PETSC_LIB}")

find_path(BOOST_INC "boost")
message("boost INC : ${BOOST_INC}")

message("eigen INC : ${PROJECT_SOURCE_DIR}/ThirdParty/eigen")
set(EIGEN_INC "${PROJECT_SOURCE_DIR}/ThirdParty/eigen")

add_executable(matrix_boost matrix_boost.cpp)
target_include_directories(matrix_boost PRIVATE ${BOOST_INC})

add_executable(matrix_eigen matrix_eigen.cpp)
target_include_directories(matrix_eigen PRIVATE ${EIGEN_INC})

