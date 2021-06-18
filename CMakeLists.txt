cmake_minimum_required(VERSION 3.20)

set(TARGET duck)
set(LIBRARY_TARGET ${TARGET}lib)

project(${TARGET})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTING  "Enable testing"  ON)

if (ENABLE_TESTING)
    include(CTest)
endif()

add_subdirectory(src)

if (ENABLE_TESTING)
    add_subdirectory(test)
endif()