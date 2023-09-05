cmake_minimum_required(VERSION 3.21)

project(libprg
        LANGUAGES C
        VERSION 0.0.1
        DESCRIPTION "Biblioteca Programação II")

set(CMAKE_C_STANDARD 17)

add_subdirectory(libprg)

# https://cmake.org/cmake/help/book/mastering-cmake/chapter/Packaging%20With%20CPack.html
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # For IDEs indexing
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

