add_executable(06_recursion_tests tests.cpp ../functions.hpp ../functions.cpp)
target_link_libraries(06_recursion_tests PRIVATE gtest gtest_main)