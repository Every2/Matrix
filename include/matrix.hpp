#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <ratio>
#include <array>
#include <variant>

using ArrayType = std::variant<int, float, std::ratio<>>;
template <std::size_t lines, std::size_t columns>
class Matrix {

public:
    Matrix() : _data({}) {}

private:
    std::array<std::array<ArrayType, columns>, lines> _data{};
};

#endif //MATRIX_HPP


