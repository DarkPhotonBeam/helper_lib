cmake_minimum_required(VERSION 3.31)
project(helper_lib C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_library(helper_lib
        src/args.c
        include/HelperLib/args.h
)

add_library(DLeuthold::HelperLib ALIAS helper_lib)

target_include_directories(helper_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    add_executable(helper_lib_main src/main.c)

    # Link the internal alias
    target_link_libraries(helper_lib_main PRIVATE DLeuthold::HelperLib)
endif()