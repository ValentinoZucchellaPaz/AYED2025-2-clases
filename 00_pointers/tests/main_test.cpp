#include <gtest/gtest.h>
#include "../funciones.hpp"

TEST(FuncTests, RefTest) {
    int x = 5;
    funcValorRef(x);
    EXPECT_EQ(x, 10);
}

TEST(FuncTests, ValueTest) {
    int x = 5;
    funcValorCopia(x);
    EXPECT_EQ(x, 5);
}