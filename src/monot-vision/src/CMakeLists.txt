cmake_minimum_required(VERSION 2.8)
project(monot-vision)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "../../../lib")
find_package(OpenCV REQUIRED)
find_package(Mosquitto REQUIRED)
include_directories(${MOSQUITTO_INCLUDE_DIR})
add_executable(monot-vision main.cpp Controller.cpp FaceDetector.cpp)
target_link_libraries(monot-vision ${OpenCV_LIBS} ${MOSQUITTO_LIBRARIES})
