#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <boost/rational.hpp>
#include "specialized_functions.h"

namespace mtx {
    template<typename TypeSpecialization, std::size_t ROWS, std::size_t COLS>
    using MatrixType = std::array<std::array<TypeSpecialization, COLS>, ROWS>;
    using Rational = boost::rational<int>;

    template<typename T, std::size_t ROWS, std::size_t COLS>
    class Matrix;

    template<std::size_t ROWS, std::size_t COLS>
    class Matrix<double, ROWS, COLS> {
    public:
        explicit Matrix(MatrixType<double, ROWS, COLS> &data) : _data(data) {}
        MatrixType<double, ROWS, COLS> sum(MatrixType<double, ROWS, COLS> &other) {
            return mtx_f::sum(_data, other);
        }

        MatrixType<double, ROWS, COLS> sub(MatrixType<double, ROWS, COLS> &other) {
            return mtx_f::sub(_data, other);
        }

        MatrixType<double, ROWS, COLS> transpose() {
            return mtx_f::transpose(_data);
        }

        MatrixType<double, ROWS, COLS> scalar(double scalar) {
            return mtx_f::scalar(_data, scalar);
        }

        MatrixType<double, ROWS, COLS> row_reduction() {
            return mtx_f::row_reduction(_data);
        }
        template<std::size_t MID>
        MatrixType<double, ROWS, COLS> product(MatrixType<double, MID, COLS> &other) {
            return mtx_f::product(_data, other);
        }

    private:
        MatrixType<double, ROWS, COLS> _data;
    };

    template<std::size_t ROWS, std::size_t COLS>
    class Matrix<int, ROWS, COLS> {
    public:
        explicit Matrix(MatrixType<int, ROWS, COLS> &data) : _data(data) {}
        MatrixType<int, ROWS, COLS> sum(MatrixType<int, ROWS, COLS> &other) {
            return mtx_f::sum(_data, other);
        }

        MatrixType<int, ROWS, COLS> sub(MatrixType<int, ROWS, COLS> &other) {
            return mtx_f::sub(_data, other);
        }

        MatrixType<int, ROWS, COLS> transpose() {
            return mtx_f::transpose(_data);
        }

        MatrixType<int, ROWS, COLS> scalar(int scalar) {
            return mtx_f::scalar(_data, scalar);
        }

        template<std::size_t MID>
        MatrixType<int, ROWS, COLS> product(MatrixType<int, MID, COLS> &other) {
            return mtx_f::product(_data, other);
        }

    private:
        MatrixType<int, ROWS, COLS> _data;
    };


    template<std::size_t ROWS, std::size_t COLS>
    class Matrix<Rational, ROWS, COLS> {
    public:
        explicit Matrix(MatrixType<Rational, ROWS, COLS> &data) : _data(data) {}
        MatrixType<Rational, ROWS, COLS> sum(MatrixType<Rational, ROWS, COLS> &other) {
            return mtx_f::sum(_data, other);
        }

        MatrixType<Rational, ROWS, COLS> sub(MatrixType<Rational, ROWS, COLS> &other) {
            return mtx_f::sub(_data, other);
        }

        MatrixType<Rational, ROWS, COLS> transpose() {
            return mtx_f::transpose(_data);
        }

        MatrixType<Rational, ROWS, COLS> scalar(int scalar) {
            return mtx_f::scalar(_data, scalar);
        }

        MatrixType<Rational, ROWS, COLS> row_reduction() {
            return mtx_f::row_reduction(_data);
        }
        template<std::size_t MID>
        MatrixType<Rational, ROWS, COLS> product(MatrixType<Rational, MID, COLS> &other) {
            return mtx_f::product(_data, other);
        }

    private:
        MatrixType<Rational, ROWS, COLS> _data;
    };

} // namespace mtx
#endif //MATRIX_HPP
