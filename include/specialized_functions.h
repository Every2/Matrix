#ifndef SPECIALIZED_FUNCTIONS_HPP
#define SPECIALIZED_FUNCTIONS_HPP

#include <array>
#include <ratio>

template<typename TypeSpecialization, std::size_t ROWS, std::size_t COLS>
using MatrixType = std::array<std::array<TypeSpecialization, ROWS>, COLS>;

template<std::size_t ROWS, std::size_t COLS>
MatrixType<double, ROWS, COLS> sum(MatrixType<double, ROWS, COLS>& matrix, MatrixType<double, ROWS, COLS>& other) {
    MatrixType result{};
    for (std::size_t i {0}; i < ROWS; ++i) {
        for (std::size_t j {0}; j < COLS; ++j) {
            result[i][j] = matrix[i][j] + other[i][j];
        }
    }
    return result;
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<int, ROWS, COLS> sum(MatrixType<int, ROWS, COLS>& matrix, MatrixType<int, ROWS, COLS>& other) {
    MatrixType<int, ROWS, COLS> result{};
    for (std::size_t i {0}; i < ROWS; ++i) {
        for (std::size_t j {0}; j < COLS; ++j) {
            result[i][j] = matrix[i][j] + other[i][j];
        }
    }
    return result;
}

template<int NUMERATOR, std::size_t ROWS, std::size_t COLS>
MatrixType<std::ratio<NUMERATOR>, ROWS, COLS> sum(MatrixType<std::ratio<NUMERATOR>, ROWS, COLS>& matrix,
    MatrixType<std::ratio<NUMERATOR>, ROWS, COLS>& other) {
    MatrixType result{};
    for (std::size_t i {0}; i < ROWS; ++i) {
        for (std::size_t j {0}; j < COLS; ++j) {
            result[i][j] = matrix[i][j] + other[i][j];
        }
    }
    return result;
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<double, ROWS, COLS> sub(MatrixType<double, ROWS, COLS>& matrix, MatrixType<double, ROWS, COLS>& other) {
        MatrixType result{};
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[i][j] = matrix[i][j] - other[i][j];
            }
        }
        return result;
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<int, ROWS, COLS> sub(MatrixType<int, ROWS, COLS>& matrix, MatrixType<int, ROWS, COLS>& other) {
        MatrixType result{};
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[i][j] = matrix[i][j] - other[i][j];
            }
        }
        return result;
}

template<int NUMERATOR, std::size_t ROWS, std::size_t COLS>
MatrixType<std::ratio<NUMERATOR>, ROWS, COLS> sub(MatrixType<std::ratio<NUMERATOR>, ROWS, COLS>& matrix,
    MatrixType<std::ratio<NUMERATOR>, ROWS, COLS>& other) {
        MatrixType result{};
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[i][j] = matrix[i][j] - other[i][j];
            }
        }
        return result;
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<double, COLS, ROWS> transpose(MatrixType<double, ROWS, COLS>& matrix) {
        MatrixType result{};
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<int, COLS, ROWS> transpose(MatrixType<int, ROWS, COLS>& matrix) {
        MatrixType result{};
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
}

template<int NUMERATOR, std::size_t ROWS, std::size_t COLS>
MatrixType<std::ratio<NUMERATOR>, COLS, ROWS> transpose(MatrixType<std::ratio<NUMERATOR>, ROWS, COLS>& matrix) {
        MatrixType result{};
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<double, ROWS, COLS> scalar(MatrixType<double, ROWS, COLS>& matrix, double scalar) {
        MatrixType result;
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[i][j] = matrix[i][j] * scalar;
            }
        }
        return result;
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<int, ROWS, COLS> scalar(MatrixType<int, ROWS, COLS>& matrix, int scalar) {
        MatrixType result;
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[i][j] = matrix[i][j] * scalar;
            }
        }
        return result;
}

template<int NUMERATOR, std::size_t ROWS, std::size_t COLS>
MatrixType<std::ratio<NUMERATOR>, ROWS, COLS> scalar(MatrixType<std::ratio<NUMERATOR>, ROWS, COLS>& matrix,
    std::ratio<NUMERATOR> scalar) {
        MatrixType result;
        for (std::size_t i {0}; i < ROWS; ++i) {
            for (std::size_t j {0}; j < COLS; ++j) {
                result[i][j] = matrix[i][j] * scalar;
            }
        }
        return result;
}

template<std::size_t N>
double determinant(MatrixType<double, N, N>& matrix) {
        if constexpr (N == 1) {
            return matrix[0][0];
        } else {
            double result {0};
            for (std::size_t i {0}; i < N; ++i) {
                MatrixType<double, N - 1, N - 1> subMatrix;
                for (std::size_t j {1}; j < N; ++j) {
                    for (std::size_t k {0}, l {0}; k < N; ++k) {
                        if (k == i) continue;
                        subMatrix[j - 1][l++] = matrix[j][k];
                    }
                }
                double sign {i % 2 == 0 ? 1.0 : -1.0};
                result += sign * matrix[0][i] * determinant(subMatrix);
            }
            return result;
        }
}

template<std::size_t N>
int determinant(MatrixType<int, N, N>& matrix) {
        if constexpr (N == 1) {
            return matrix[0][0];
        } else {
            int result {0};
            for (std::size_t i {0}; i < N; ++i) {
                MatrixType<int, N - 1, N - 1> subMatrix;
                for (std::size_t j {1}; j < N; ++j) {
                    for (std::size_t k {0}, l {0}; k < N; ++k) {
                        if (k == i) continue;
                        subMatrix[j - 1][l++] = matrix[j][k];
                    }
                }
                int sign {i % 2 == 0 ? 1 : -1};
                result += sign * matrix[0][i] * determinant(subMatrix);
            }
            return result;
        }
}

template<int NUMERATOR,std::size_t N>
int determinant(MatrixType<std::ratio<NUMERATOR>, N, N>& matrix) {
        if constexpr (N == 1) {
            return matrix[0][0];
        } else {
            std::ratio<NUMERATOR> result {0};
            for (std::size_t i {0}; i < N; ++i) {
                MatrixType<std::ratio<NUMERATOR>, N - 1, N - 1> subMatrix;
                for (std::size_t j {1}; j < N; ++j) {
                    for (std::size_t k {0}, l {0}; k < N; ++k) {
                        if (k == i) continue;
                        subMatrix[j - 1][l++] = matrix[j][k];
                    }
                }
                std::ratio<NUMERATOR> sign {i % 2 == 0 ? 1 : -1};
                result += sign * matrix[0][i] * determinant(subMatrix);
            }
            return result;
        }
}

template<std::size_t ROWS, std::size_t COLS>
MatrixType<double, ROWS, COLS> row_reduction(MatrixType<double, ROWS, COLS>& matrix) {
        MatrixType result {matrix};
        size_t line {0};
        for (std::size_t j {0}; j < COLS; ++j) {
            int n {-1};
            for (std::size_t i {line}; i < ROWS; ++i) {
                if (result[i][j] != double{}) {
                    n = static_cast<int>(i);
                    break;
                }
            }
            if (n < 0) continue;
            if (line != static_cast<std::size_t>(n)) {
                for (std::size_t k {0}; k < COLS; ++k) {
                    double aux {result[line][k]};
                    result[line][k] = result[n][k];
                    result[n][k] = aux;
                }
            }
            double factor {result[line][j]};
            for (std::size_t k {0}; k < COLS; ++k) {
                result[line][k] = result[line][k] / factor;
            }
            for (std::size_t i {0}; i < ROWS; ++i) {
                if (i == line) continue;
                double _factor {result[i][j]};
                for (std::size_t k {0}; k < COLS; ++k) {
                    result[i][k] = result[i][k] - result[line][k] * _factor;
                }
            }
            line += 1;
        }
        return result;
}


template<int NUMERATOR,std::size_t ROWS, std::size_t COLS>
MatrixType<std::ratio<NUMERATOR>, ROWS, COLS> row_reduction(MatrixType<std::ratio<NUMERATOR>, ROWS, COLS>& matrix) {
        MatrixType result {matrix};
        size_t line {0};
        for (std::size_t j {0}; j < COLS; ++j) {
            int n {-1};
            for (std::size_t i {line}; i < ROWS; ++i) {
                if (result[i][j] != std::ratio<NUMERATOR>{}) {
                    n = static_cast<int>(i);
                    break;
                }
            }
            if (n < 0) continue;
            if (line != static_cast<std::size_t>(n)) {
                for (std::size_t k {0}; k < COLS; ++k) {
                    std::ratio<NUMERATOR> aux {result[line][k]};
                    result[line][k] = result[n][k];
                    result[n][k] = aux;
                }
            }
            std::ratio<NUMERATOR> factor {result[line][j]};
            for (std::size_t k {0}; k < COLS; ++k) {
                result[line][k] = result[line][k] / factor;
            }
            for (std::size_t i {0}; i < ROWS; ++i) {
                if (i == line) continue;
                std::ratio<NUMERATOR> _factor {result[i][j]};
                for (std::size_t k {0}; k < COLS; ++k) {
                    result[i][k] = result[i][k] - result[line][k] * _factor;
                }
            }
            line += 1;
        }
        return result;
}



#endif //SPECIALIZED_FUNCTIONS_HPP
