#include <gtest/gtest.h>
#include "../functions.hpp"

TEST(RecursionTests, Sumatoria){
    int resultado = sumatoriaIter(5);
    EXPECT_EQ(resultado, 15);
}

TEST(RecursionTests, SumatoriaRecOK){
    int resultado = sumatoriaRec(5);
    EXPECT_EQ(resultado, 15);
}

TEST(RecursionTests, SumatoriaRecMenor0){
    EXPECT_ANY_THROW(sumatoriaRec(-1));
}

TEST(RecursionTests,SumatoriaRecIgual0){
    int resultado = sumatoriaRec(0);
    EXPECT_EQ(resultado, 0);
}

TEST(RecursionTests, Fibonacci){
    int resultado = fibonacciIter(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciIter(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciIter(5);
    EXPECT_EQ(resultado, 5);
}

TEST(RecursionTests, FibonacciRec){
    int resultado = fibonacciRec(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciRec(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciRec(5);
    EXPECT_EQ(resultado, 5);
}

TEST(RecursionTests, FibonacciTail){
    int resultado = fibonacciTail(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciTail(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciTail(5);
    EXPECT_EQ(resultado, 5);
}

TEST(RecursionTests, FibonacciTailIter){
    int resultado = fibonacciTailIter(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciTailIter(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciTailIter(5);
    EXPECT_EQ(resultado, 5);
}