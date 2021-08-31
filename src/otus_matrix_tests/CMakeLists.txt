cmake_minimum_required(VERSION 3.0.0)
project(otus_matrix_tests C CXX)

set(CMAKE_CXX_STANDARD 17)
if(MSVC)
    add_definitions(-D_SCL_SECURE_NO_WARNINGS /wd4251 /wd4275 /wd4003 /wd4005 /wd4503 /wd4290 )
endif()

include_directories(${CONAN_INCLUDE_DIRS})
include_directories(${otus_matrix_lib_SOURCE_DIR}/include)
include_directories(${otus_matrix_tests_SOURCE_DIR}/include)

FILE(GLOB TestFiles ${PROJECT_SOURCE_DIR}/test_files/*)
source_group(test_files FILES ${TestFiles})

configure_file(layout.hpp.in ${PROJECT_BINARY_DIR}/layout.hpp)
include_directories(${PROJECT_BINARY_DIR}/)

set(SOURCE_FILES
	src/main.cpp
   )
	
source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCE_FILES})
	
add_executable(otus_matrix_tests ${SOURCE_FILES} ${TestFiles} ${PROJECT_BINARY_DIR}/layout.hpp)
target_link_libraries(otus_matrix_tests otus_matrix_lib ${CONAN_LIBS})
add_test(NAME "otus_matrix_tests" COMMAND otus_matrix_tests)