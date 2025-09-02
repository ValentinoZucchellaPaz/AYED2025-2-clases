add_executable(pointers_tests main_test.cpp ../funciones.cpp ../funciones.hpp)
target_link_libraries(pointers_tests PRIVATE gtest gtest_main)