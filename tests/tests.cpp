#include <gtest/gtest.h>
#include "../include/specialized_functions.h"
#include <boost/rational.hpp>

MatrixType<Rational, 3, 2> matrix = {{
    {{ Rational(2), Rational(3) }},
    {{ Rational(8), Rational(1) }},
    {{ Rational(-4), Rational(0) }}
}};

MatrixType<Rational, 3, 2> other = {{
    {{ Rational(4), Rational(5) }},
    {{ Rational(-9), Rational(6) }},
    {{ Rational(2), Rational(7) }}
}};


TEST(MatrixOperationsTest, MatrixSum) {

    auto result = sum(matrix, other);


    ASSERT_EQ(result[0][0], Rational(6));
    ASSERT_EQ(result[0][1], Rational(8));
    ASSERT_EQ(result[1][0], Rational(-1));
    ASSERT_EQ(result[1][1], Rational(7));
    ASSERT_EQ(result[2][0], Rational(-2));
    ASSERT_EQ(result[2][1], Rational(7));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}