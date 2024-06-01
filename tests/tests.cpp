#include <gtest/gtest.h>
#include "../include/specialized_functions.h"

TEST(SumTest, MatrixSum) {
    MatrixType<Rational, 3, 2> matrix {{
        {{ Rational(2), Rational(3) }},
        {{ Rational(8), Rational(1) }},
        {{ Rational(-4), Rational(0) }}
    }};

    MatrixType<Rational, 3, 2> other {{
        {{ Rational(4), Rational(5) }},
        {{ Rational(-9), Rational(6) }},
        {{ Rational(2), Rational(7) }}
    }};

    auto result = sum(matrix, other);

    ASSERT_EQ(result[0][0], Rational(6));
    ASSERT_EQ(result[0][1], Rational(8));
    ASSERT_EQ(result[1][0], Rational(-1));
    ASSERT_EQ(result[1][1], Rational(7));
    ASSERT_EQ(result[2][0], Rational(-2));
    ASSERT_EQ(result[2][1], Rational(7));
}

TEST(RowReductionTest, MatrixRowReduction) {
    MatrixType<Rational, 4, 4> matrix {{
        {{
            Rational(1, 1),
            Rational(1, 1),
            Rational(1, 1),
            Rational(6, 1),
        }},
        {{
            Rational(2, 1),
            Rational(-1, 1),
            Rational(3, 1),
            Rational(11, 1),
        }},
        {{
            Rational(4, 1),
            Rational(-3, 1),
            Rational(2, 1),
            Rational(0, 1),
        }},
        {{
            Rational(3, 1),
            Rational(1, 1),
            Rational(1, 1),
            Rational(4, 1),
        }}
    }};

    auto result = row_reduction(matrix);

    MatrixType<Rational, 4, 4> expected_result = {{
        {{
            Rational(1, 1),
            Rational(0, 1),
            Rational(0, 1),
            Rational(-1, 1),
        }},
        {{
            Rational(0, 1),
            Rational(1, 1),
            Rational(0, 1),
            Rational(2, 1),
        }},
        {{
            Rational(0, 1),
            Rational(0, 1),
            Rational(1, 1),
            Rational(5, 1),
        }},
        {{
            Rational(0, 1),
            Rational(0, 1),
            Rational(0, 1),
            Rational(0, 1),
        }}
    }};

    ASSERT_EQ(result, expected_result);
}

TEST(ScalarSubTest, ScalarSubtraction) {
    MatrixType<Rational, 2, 3> matrix {{
        {{
            Rational(2, 1),
            Rational(3, 1),
            Rational(8, 1),
        }},
        {{
            Rational(1, 1),
            Rational(-4, 1),
            Rational(0, 1),
        }},
    }};

    MatrixType<Rational, 2, 3> other = {{
        {{
            Rational(4, 1),
            Rational(5, 1),
            Rational(-9, 1),
        }},
        {{
            Rational(6, 1),
            Rational(2, 1),
            Rational(7, 1),
        }},
    }};

    MatrixType<Rational, 2, 3> scalar_result = {{
        {{
            Rational(0, 1),
            Rational(1, 1),
            Rational(25, 1),
        }},
        {{
            Rational(-4, 1),
            Rational(-10, 1),
            Rational(-7, 1),
        }},
    }};

    auto scalar_result_actual = scalar(matrix, 2);

    auto result = sub(scalar_result_actual, other);

    ASSERT_EQ(result, scalar_result);
}

TEST(DeterminantTest, MatrixDeterminant) {
    MatrixType<Rational, 2, 2> matrix {{
        {{
            Rational(1, 1),
            Rational(2, 1),
        }},
        {{
            Rational(3, 1),
            Rational(4, 1),
        }},
    }};

    auto actual_result = determinant(matrix);

    ASSERT_EQ(actual_result, -2);
}

TEST(TransposeTest, MatrixTranspose) {
    MatrixType<Rational, 3, 2> matrix {{
        {{
            Rational(2, 1),
            Rational(0, 1),
        }},
        {{
            Rational(8, 1),
            Rational(6, 1),
        }},
        {{
            Rational(-4, 1),
            Rational(-10, 1),
        }},
    }};

    auto result = transpose(matrix);

    MatrixType<Rational, 2, 3> expected_result {{
        {{
            Rational(2, 1),
            Rational(8, 1),
            Rational(-4, 1),
        }},
        {{
            Rational(0, 1),
            Rational(6, 1),
            Rational(-10, 1),
        }},
    }};
    ASSERT_EQ(result, expected_result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}