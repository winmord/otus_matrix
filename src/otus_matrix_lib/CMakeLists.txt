cmake_minimum_required(VERSION 3.0.0)
project(otus_matrix_lib C CXX)

set(CMAKE_CXX_STANDARD 17)
if(MSVC)
    add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
endif()

add_definitions(-DOTUS_MATRIX_LIB_DLL_EXPORTS)
if (${BUILD_SHARED_LIBS})
    add_definitions(-DOTUS_MATRIX_LIB_DLL)
endif ()

if(MSVC)
    add_definitions(/wd4251 /wd4275 /wd4003 /wd4005 /wd4503 /wd4290 -D_SCL_SECURE_NO_WARNINGS)
else ()
    message("not ready for non-msvc compilation")
endif ()

include_directories(${otus_matrix_lib_SOURCE_DIR}/include)

set(SOURCE_FILES
		include/otus_matrix_lib/matrix.hpp
		include/otus_matrix_lib/matrix_operation_base.hpp
		include/otus_matrix_lib/matrix_operation_det.hpp
		include/otus_matrix_lib/matrix_operation_sum.hpp
		include/otus_matrix_lib/matrix_operation_trans.hpp
		include/otus_matrix_lib/otus_matrix_api.hpp
		
		src/matrix_operation_base.cpp
	)

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCE_FILES} )
	
add_library(otus_matrix_lib ${SOURCE_FILES})
target_link_libraries(otus_matrix_lib ${CONAN_LIBS})