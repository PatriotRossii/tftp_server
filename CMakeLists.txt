cmake_minimum_required (VERSION 3.5)

project(tftp_server)

find_package(Boost 1.74 COMPONENTS program_options system REQUIRED)

add_executable(tftp_server tftp_server/main.cpp)
target_link_libraries(tftp_server Boost::program_options Boost::system)