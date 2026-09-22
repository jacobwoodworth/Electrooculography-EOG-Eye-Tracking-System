cmake_minimum_required(VERSION 3.24)
project(PC LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(BOOST_INCLUDE_LIBRARIES asio)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
        Boost
        URL https://github.com/boostorg/boost/releases/download/boost-1.86.0/boost-1.86.0-cmake.tar.xz
        DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_MakeAvailable(Boost)

add_executable(PC main.cpp)
target_link_libraries(PC PRIVATE Boost::asio)