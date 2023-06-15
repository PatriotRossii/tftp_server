cmake_minimum_required (VERSION 3.5)

project(tftp_server)

add_executable(tftp_server tftp_server/main.cpp)

find_package(tftp_common 1.2.0)

if (NOT tftp_common_FOUND)
	include(FetchContent)

	FetchContent_Declare(
	  tftp_common
	  URL https://github.com/eoan-ermine/tftp_common/archive/refs/tags/v1.2.0.zip
	)

	FetchContent_GetProperties(tftp_common)
	if (NOT tftp_common_POPULATED)
		FetchContent_Populate(tftp_common)
	endif()

	add_library(tftp_common INTERFACE)
	target_include_directories(tftp_common INTERFACE ${tftp_common_SOURCE_DIR})
	target_link_libraries(tftp_server tftp_common)
endif()


find_package(Boost 1.74 COMPONENTS program_options system REQUIRED)

target_link_libraries(tftp_server Boost::program_options Boost::system)