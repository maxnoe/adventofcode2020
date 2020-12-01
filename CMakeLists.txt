cmake_minimum_required(VERSION 3.15...3.19 FATAL_ERROR)


project(aoc_maxnoe_2020 VERSION 0.1.1 LANGUAGES CXX)



find_package(OpenSSL REQUIRED)

add_library(aocmaxnoe20 src/aocmaxnoe20.cpp)
set_property(TARGET aocmaxnoe20 PROPERTY PUBLIC_HEADER include/aocmaxnoe20.h;)
target_include_directories(aocmaxnoe20 PRIVATE vendor)
target_include_directories(aocmaxnoe20 PRIVATE include)
target_link_libraries(aocmaxnoe20 PRIVATE OpenSSL::SSL OpenSSL::Crypto)


function(add_day day)
    add_executable(aoc_maxnoe_day${day} src/day${day}.cpp)

    # make sure we use cpp 20
    target_compile_features(aoc_maxnoe_day${day} PRIVATE cxx_std_20)
    target_link_libraries(aoc_maxnoe_day${day} aocmaxnoe20)
    target_include_directories(aoc_maxnoe_day${day} PRIVATE include)
endfunction()


foreach(day RANGE 1 1)
    add_day(${day})
endforeach(day)
