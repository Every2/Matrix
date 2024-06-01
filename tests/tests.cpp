#include <gtest/gtest.h>
#include "../include/specialized_functions.h"
#include <boost/rational.hpp>

// Definição dos valores das matrizes
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

// Teste para verificar a soma das matrizes
TEST(MatrixOperationsTest, MatrixSum) {
    // Realizando a soma das matrizes
    auto result = sum(matrix, other);

    // Verificando o resultado
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