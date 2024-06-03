#include <gtest/gtest.h>
#include "../include/specialized_functions.h"


TEST(SumTest, MatrixSum) {
    mtx_f::MatrixType<mtx_f::Rational, 3, 2> matrix {{
        {{ mtx_f::Rational(2), mtx_f::Rational(3) }},
        {{ mtx_f::Rational(8), mtx_f::Rational(1) }},
        {{ mtx_f::Rational(-4), mtx_f::Rational(0) }}
    }};

    mtx_f::MatrixType<mtx_f::Rational, 3, 2> other {{
        {{ mtx_f::Rational(4), mtx_f::Rational(5) }},
        {{ mtx_f::Rational(-9), mtx_f::Rational(6) }},
        {{ mtx_f::Rational(2), mtx_f::Rational(7) }}
    }};

    auto result = mtx_f::sum(matrix, other);

    ASSERT_EQ(result[0][0], mtx_f::Rational(6));
    ASSERT_EQ(result[0][1], mtx_f::Rational(8));
    ASSERT_EQ(result[1][0], mtx_f::Rational(-1));
    ASSERT_EQ(result[1][1], mtx_f::Rational(7));
    ASSERT_EQ(result[2][0], mtx_f::Rational(-2));
    ASSERT_EQ(result[2][1], mtx_f::Rational(7));
}

TEST(RowReductionTest, MatrixRowReduction) {
    mtx_f::MatrixType<mtx_f::Rational, 4, 4> matrix {{
        {{
            mtx_f::Rational(1, 1),
            mtx_f::Rational(1, 1),
            mtx_f::Rational(1, 1),
            mtx_f::Rational(6, 1),
        }},
        {{
            mtx_f::Rational(2, 1),
            mtx_f::Rational(-1, 1),
            mtx_f::Rational(3, 1),
            mtx_f::Rational(11, 1),
        }},
        {{
           mtx_f::Rational(4, 1),
            mtx_f::Rational(-3, 1),
            mtx_f::Rational(2, 1),
           mtx_f::Rational(0, 1),
        }},
        {{
            mtx_f::Rational(3, 1),
            mtx_f::Rational(1, 1),
            mtx_f::Rational(1, 1),
            mtx_f::Rational(4, 1),
        }}
    }};

    auto result = mtx_f::row_reduction(matrix);

    mtx_f::MatrixType<mtx_f::Rational, 4, 4> expected_result = {{
        {{
            mtx_f::Rational(1, 1),
            mtx_f::Rational(0, 1),
            mtx_f::Rational(0, 1),
            mtx_f::Rational(-1, 1),
        }},
        {{
            mtx_f::Rational(0, 1),
            mtx_f::Rational(1, 1),
            mtx_f::Rational(0, 1),
            mtx_f::Rational(2, 1),
        }},
        {{
           mtx_f::Rational(0, 1),
            mtx_f::Rational(0, 1),
            mtx_f::Rational(1, 1),
            mtx_f::Rational(5, 1),
        }},
        {{
            mtx_f::Rational(0, 1),
            mtx_f::Rational(0, 1),
            mtx_f::Rational(0, 1),
            mtx_f::Rational(0, 1),
        }}
    }};

    ASSERT_EQ(result, expected_result);
}

TEST(ScalarSubTest, ScalarSubtraction) {
    mtx_f::MatrixType<mtx_f::Rational, 2, 3> matrix {{
        {{
            mtx_f::Rational(2, 1),
            mtx_f::Rational(3, 1),
            mtx_f::Rational(8, 1),
        }},
        {{
            mtx_f::Rational(1, 1),
            mtx_f::Rational(-4, 1),
            mtx_f::Rational(0, 1),
        }},
    }};

    mtx_f::MatrixType<mtx_f::Rational, 2, 3> other = {{
        {{
            mtx_f::Rational(4, 1),
            mtx_f::Rational(5, 1),
            mtx_f::Rational(-9, 1),
        }},
        {{
            mtx_f::Rational(6, 1),
            mtx_f::Rational(2, 1),
            mtx_f::Rational(7, 1),
        }},
    }};

    mtx_f::MatrixType<mtx_f::Rational, 2, 3> scalar_result = {{
        {{
            mtx_f::Rational(0, 1),
            mtx_f::Rational(1, 1),
            mtx_f::Rational(25, 1),
        }},
        {{
            mtx_f::Rational(-4, 1),
            mtx_f::Rational(-10, 1),
            mtx_f::Rational(-7, 1),
        }},
    }};

    auto scalar_result_actual = mtx_f::scalar(matrix, 2);

    auto result = mtx_f::sub(scalar_result_actual, other);

    ASSERT_EQ(result, scalar_result);
}

TEST(DeterminantTest, MatrixDeterminant) {
    mtx_f::MatrixType<mtx_f::Rational, 2, 2> matrix {{
        {{
            mtx_f::Rational(1, 1),
            mtx_f::Rational(2, 1),
        }},
        {{
            mtx_f::Rational(3, 1),
            mtx_f::Rational(4, 1),
        }},
    }};

    auto actual_result = mtx_f::determinant(matrix);

    ASSERT_EQ(actual_result, -2);
}

TEST(TransposeTest, MatrixTranspose) {
    mtx_f::MatrixType<mtx_f::Rational, 3, 2> matrix {{
        {{
            mtx_f::Rational(2, 1),
            mtx_f::Rational(0, 1),
        }},
        {{
            mtx_f::Rational(8, 1),
            mtx_f::Rational(6, 1),
        }},
        {{
            mtx_f::Rational(-4, 1),
            mtx_f::Rational(-10, 1),
        }},
    }};

    auto result = mtx_f::transpose(matrix);

    mtx_f::MatrixType<mtx_f::Rational, 2, 3> expected_result {{
        {{
            mtx_f::Rational(2, 1),
            mtx_f::Rational(8, 1),
            mtx_f::Rational(-4, 1),
        }},
        {{
            mtx_f::Rational(0, 1),
            mtx_f::Rational(6, 1),
            mtx_f::Rational(-10, 1),
        }},
    }};
    ASSERT_EQ(result, expected_result);
}

TEST(FormulaMultiTest, MatrixFormulaMulti) {
    mtx_f::MatrixType<mtx_f::Rational, 2, 3> matrix = {{
        {{
            mtx_f::Rational(1, 1),
            mtx_f::Rational(2, 1),
            mtx_f::Rational(3, 1),
        }},
        {{
            mtx_f::Rational(0, 1),
            mtx_f::Rational(6, 1),
            mtx_f::Rational(1, 1),
        }},
    }};

    mtx_f::MatrixType<mtx_f::Rational, 3, 2> another = {{
        {{
            mtx_f::Rational(1, 1),
            mtx_f::Rational(1, 1),
        }},
        {{
            mtx_f::Rational(4, 1),
            mtx_f::Rational(4, 1),
        }},
        {{
            mtx_f::Rational(2, 1),
            mtx_f::Rational(2, 1),
        }},
    }};

    mtx_f::MatrixType<mtx_f::Rational, 2, 2> result = {{
        {{
            mtx_f::Rational(15, 1),
            mtx_f::Rational(15, 1),
        }},
        {{
            mtx_f::Rational(26, 1),
            mtx_f::Rational(26, 1),
        }},
    }};

    auto actual_result = mtx_f::product(matrix, another);

    ASSERT_EQ(actual_result, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}