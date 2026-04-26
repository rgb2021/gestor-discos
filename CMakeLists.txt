cmake_minimum_required(VERSION 3.14)

project(gestor_discos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_library(gestor_discos_lib
    src/GestorDiscos.cpp
)

target_include_directories(gestor_discos_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(gestor_discos
    app/main.cpp
)

target_link_libraries(gestor_discos
    PRIVATE
        gestor_discos_lib
)

enable_testing()

add_executable(gestor_discos_tests
    tests/test_gestor_discos.cpp
)

target_link_libraries(gestor_discos_tests
    PRIVATE
        gestor_discos_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gestor_discos_tests)