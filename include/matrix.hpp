#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include "../include/specialized_functions.h"
#include <boost/rational.hpp>

namespace mtx {
    template<typename TypeSpecialization, std::size_t ROWS, std::size_t COLS>
    using MatrixType = std::array<std::array<TypeSpecialization, COLS>, ROWS>;
    using Rational = boost::rational<int>;
    template<std::size_t ROWS, std::size_t COLS>

    class Matrix {

    public:
        explicit Matrix(MatrixType<double, ROWS, COLS> &data) : _double_data(data) {}
        explicit Matrix(MatrixType<int, ROWS, COLS> &data) : _int_data(data) {}
        explicit Matrix(MatrixType<Rational, ROWS, COLS> &data) : _rational_data(data) {}

        MatrixType<double, ROWS, COLS> sum(MatrixType<double, ROWS, COLS> &other);
        MatrixType<int, ROWS, COLS> sum(MatrixType<int, ROWS, COLS> &other);
        MatrixType<Rational, ROWS, COLS> sum(MatrixType<Rational, ROWS, COLS> &other);

        MatrixType<double, ROWS, COLS> sub(MatrixType<double, ROWS, COLS> &other);
        MatrixType<int, ROWS, COLS> sub(MatrixType<int, ROWS, COLS> &other);
        MatrixType<Rational, ROWS, COLS> sub(MatrixType<Rational, ROWS, COLS> &other);

        template<double  T>
        MatrixType<double, ROWS, COLS> transpose();

        template<int T>
        MatrixType<int, ROWS, COLS> transpose();
        MatrixType<Rational, ROWS, COLS> transpose();

        MatrixType<Rational, ROWS, COLS> scalar(int scalar);
        MatrixType<double, ROWS, COLS> scalar(double scalar);

        template<int T>
        MatrixType<int, ROWS, COLS> scalar(int scalar);

        template<std::size_t N>
        static int determinant(MatrixType<int, N, N> &matrix);

        template<std::size_t N>
        static double determinant(MatrixType<double, N, N> &matrix);

        template<std::size_t N>
        static Rational determinant(MatrixType<Rational, N, N> &matrix);

        template<double  T>
        MatrixType<double, ROWS, COLS> row_reduction();
        MatrixType<Rational, ROWS, COLS> row_reduction();

        template<std::size_t MID>
        MatrixType<int, ROWS, COLS> product(MatrixType<int, MID, COLS> &other);

        template<std::size_t MID>
        MatrixType<double, ROWS, COLS> product(MatrixType<double, MID, COLS> &other);

        template<std::size_t MID>
        MatrixType<Rational, ROWS, COLS> product(MatrixType<Rational, MID, COLS> &other);

    private:
        MatrixType<double, ROWS, COLS> _double_data;
        MatrixType<int, ROWS, COLS> _int_data;
        MatrixType<Rational, ROWS, COLS> _rational_data;
    };
}




#endif //MATRIX_HPP


