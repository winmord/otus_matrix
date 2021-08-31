cmake_minimum_required(VERSION 3.0.0)
project(otus_matrix CXX)

set(CMAKE_CXX_STANDARD 17)
if(MSVC)
	add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
	add_definitions(-D_WIN32_WINNT=0x0601)
endif(MSVC)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(src/otus_matrix_lib)
add_subdirectory(src/otus_matrix_exe)

enable_testing()
add_subdirectory(src/otus_matrix_tests)

set_property(GLOBAL PROPERTY USE_FOLDERS 1)  