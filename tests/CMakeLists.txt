add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/googletest" "extern/googletest")

# see https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)


macro(aoc_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main aocmaxnoe20)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
    target_compile_features(${TESTNAME} PRIVATE cxx_std_20)
endmacro()

aoc_add_test(test_common test_common.cpp)
foreach(day RANGE 1 ${MAX_DAY})
    aoc_add_test(test_day${day} day${day}.cpp)
endforeach(day)
