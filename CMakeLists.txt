cmake_minimum_required(VERSION 3.15...3.19 FATAL_ERROR)

set(MAX_DAY 9)

project(aoc_maxnoe_2020 VERSION 0.${MAX_DAY}.1 LANGUAGES CXX)

# IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(OpenSSL REQUIRED)

add_library(aocmaxnoe20 src/common.cpp)
set_property(TARGET aocmaxnoe20 PROPERTY PUBLIC_HEADER include/aocmaxnoe20.h;)
target_include_directories(aocmaxnoe20 PRIVATE vendor)
target_include_directories(aocmaxnoe20 PUBLIC include)
target_link_libraries(aocmaxnoe20 PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_compile_options(aocmaxnoe20 PRIVATE -Wall -Wextra -pedantic)
target_compile_features(aocmaxnoe20 PRIVATE cxx_std_20)


function(add_day day)
    target_sources(aocmaxnoe20 PRIVATE src/day${day}.cpp)
    add_executable(aoc_maxnoe_day${day} cli/day${day}.cpp)

    # make sure we use cpp 20
    target_compile_features(aoc_maxnoe_day${day} PRIVATE cxx_std_20)
    target_compile_options(aoc_maxnoe_day${day} PRIVATE -Wall -Wextra -pedantic)

    target_link_libraries(aoc_maxnoe_day${day} aocmaxnoe20)
    target_include_directories(aoc_maxnoe_day${day} PRIVATE include)
endfunction()



include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()


foreach(day RANGE 1 ${MAX_DAY})
    add_day(${day})
endforeach(day)
