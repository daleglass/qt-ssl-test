cmake_minimum_required(VERSION 3.16)

project(qt-ssl-test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)


find_package(QT NAMES Qt5 COMPONENTS Core Network REQUIRED)
find_package(Qt5 COMPONENTS Core Network REQUIRED)

message(STATUS "Building browser with Qt ${QT_VERSION}")

add_executable(qt-ssl-test qt-ssl-test.cpp)
target_link_libraries(qt-ssl-test PRIVATE Qt${QT_VERSION_MAJOR}::Network)


