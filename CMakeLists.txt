cmake_minimum_required( VERSION 2.8 )
project ( YetAnotherSLAM )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3" )

#list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

############### dependencies ######################
# Eigen
find_package(Eigen3 REQUIRED)
if(NOT Eigen3_FOUND)
   message(FATAL_ERROR "Eigen3 not found.")
endif()
include_directories(  ${EIGEN3_INCLUDE_DIRS})
# OpenCV
find_package( OpenCV 3.2.0 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Sophus 
find_package( Sophus REQUIRED )
if(NOT Sophus_FOUND)
   message(FATAL_ERROR "Sophus not found.")
endif()
include_directories( ${SOPHUS_INCLUDE_DIRS})
# G2O
#find_package( G2O REQUIRED )
#include_directories( ${G2O_INCLUDE_DIRS} )

set( THIRD_PARTY_LIBS 
    ${OpenCV_LIBS}
   # ${Sophus_LIBRARIES}
  
#    g2o_core g2o_stuff g2o_types_sba
)
############### dependencies ######################
include_directories( ${PROJECT_SOURCE_DIR}/include )
#search sophus in ros include path /opt/ros/melodic/include/sophus
include_directories( "/opt/ros/melodic/include/")
add_subdirectory( src )
#add_subdirectory( test )