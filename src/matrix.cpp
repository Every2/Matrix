#include "../include/matrix.hpp"

namespace mtx {
    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<Rational, ROWS, COLS> Matrix<ROWS, COLS>::sum(MatrixType<Rational, ROWS, COLS> &other) {
        return mtx_f::sum(_rational_data, other);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<double, ROWS, COLS> Matrix<ROWS, COLS>::sub(MatrixType<double, ROWS, COLS> &other) {
        return mtx_f::sub(_double_data, other);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<int, ROWS, COLS> Matrix<ROWS, COLS>::sub(MatrixType<int, ROWS, COLS> &other) {
        return mtx_f::sub(_int_data, other);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<Rational, ROWS, COLS> Matrix<ROWS, COLS>::sub(MatrixType<Rational, ROWS, COLS> &other) {
        return mtx_f::sub(_rational_data, other);
    }
    template<std::size_t ROWS, std::size_t COLS>

    template<double T>
    MatrixType<double, ROWS, COLS> Matrix<ROWS, COLS>::transpose() {
        return mtx_f::transpose(_double_data);
    }
    template<std::size_t ROWS, std::size_t COLS>

    template<int T>
    MatrixType<int, ROWS, COLS> Matrix<ROWS, COLS>::transpose() {
        return mtx_f::transpose(_int_data);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<Rational, ROWS, COLS> Matrix<ROWS, COLS>::transpose() {
        return mtx_f::transpose(_rational_data);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<Rational, ROWS, COLS> Matrix<ROWS, COLS>::scalar(int scalar) {
        return mtx_f::scalar(_rational_data, scalar);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<double, ROWS, COLS> Matrix<ROWS, COLS>::scalar(double scalar) {
        return mtx_f::scalar(_double_data, scalar);
    }
    template<std::size_t ROWS, std::size_t COLS>

    template<int T>
    MatrixType<int, ROWS, COLS> Matrix<ROWS, COLS>::scalar(int scalar) {
        return mtx_f::scalar(_int_data, scalar);
    }

    template<std::size_t ROWS, std::size_t COLS>
    template<std::size_t N>
    int Matrix<ROWS, COLS>::determinant(MatrixType<int, N, N> &matrix) {
        return mtx_f::determinant(matrix);
    }

    template<std::size_t ROWS, std::size_t COLS>
    template<std::size_t N>
    double Matrix<ROWS, COLS>::determinant(MatrixType<double, N, N> &matrix) {
        return mtx_f::determinant(matrix);
    }

    template<std::size_t ROWS, std::size_t COLS>
    template<std::size_t N>
    Rational Matrix<ROWS, COLS>::determinant(MatrixType<Rational, N, N> &matrix) {
        return mtx_f::determinant(matrix);
    }

    template<std::size_t ROWS, std::size_t COLS>
    template<double T>
    MatrixType<double, ROWS, COLS> Matrix<ROWS, COLS>::row_reduction() {
        return mtx_f::row_reduction(_double_data);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<Rational, ROWS, COLS> Matrix<ROWS, COLS>::row_reduction() {
        return mtx_f::row_reduction(_rational_data);
    }

    template<std::size_t ROWS, std::size_t COLS>
    template<std::size_t MID>
    MatrixType<int, ROWS, COLS> Matrix<ROWS, COLS>::product(MatrixType<int, MID, COLS> &other) {
        return mtx_f::product(_int_data, other);
    }

    template<std::size_t ROWS, std::size_t COLS>
    template<std::size_t MID>
    MatrixType<double, ROWS, COLS> Matrix<ROWS, COLS>::product(MatrixType<double, MID, COLS> &other) {
        return mtx_f::product(_double_data, other);
    }

    template<std::size_t ROWS, std::size_t COLS>
    template<std::size_t MID>
    MatrixType<Rational, ROWS, COLS> Matrix<ROWS, COLS>::product(MatrixType<Rational, MID, COLS> &other) {
        return mtx_f::product(_rational_data, other);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<double, ROWS, COLS> Matrix<ROWS, COLS>::sum(MatrixType<double, ROWS, COLS> &other) {
        return mtx_f::sum(_double_data, other);
    }

    template<std::size_t ROWS, std::size_t COLS>
    MatrixType<int, ROWS, COLS> Matrix<ROWS, COLS>::sum(MatrixType<int, ROWS, COLS> &other) {
        return mtx_f::sum(_int_data, other);
    }


}