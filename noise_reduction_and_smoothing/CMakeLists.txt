cmake_minimum_required(VERSION 3.15)
project(noise_reduction_and_smoothing)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(noise_reduction_and_smoothing main.cpp)

target_link_libraries(noise_reduction_and_smoothing ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


