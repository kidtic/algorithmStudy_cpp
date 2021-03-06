cmake_minimum_required(VERSION 2.8)
project(algorithmstudy)

# 添加cmake模块以使用g2o

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}   -Wall  -O3  ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall   -O3 ")

# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
   add_definitions(-DCOMPILEDWITHC11)
   message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
   add_definitions(-DCOMPILEDWITHC0X)
   message(STATUS "Using flag -std=c++0x.")
else()
   message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

find_package(jsoncpp  REQUIRED)

include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/datastructure/include
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

#add_library(${PROJECT_NAME} SHARED
#src/TrackBlock.cpp
#)

#target_link_libraries(${PROJECT_NAME}
#${OpenCV_LIBS}
#)

# Build examples
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(lib_DIR /usr/lib/x84_64-linux-gnu)
link_directories(${lib_DIR})

#钢条切割问题
add_executable(steelbar_cut exercise/steelbar_cut.cpp)
target_link_libraries(steelbar_cut libjsoncpp.a)
#json数据测试
add_executable(jsondata exercise/jsondata.cpp)
target_link_libraries(jsondata libjsoncpp.a)
#路径规划
add_executable(pathplanning exercise/pathplanning.cpp)
target_link_libraries(pathplanning libjsoncpp.a)
#排序
add_executable(sort exercise/sort.cpp)
target_link_libraries(sort libjsoncpp.a)




