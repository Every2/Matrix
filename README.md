# MATRIX

[PT-BR](docs/translations/README.md)

Matrix is a header-only library with some matrix operations used in linear algebra.


### Dependencies


Matrix has two dependencies:


- Google Test - For Tests, if you wanna run
- Boost Rational  - for Rational Type


For these two, a conanfile.txt is provided to facilitate the process.

### How to run


First you need to have conan installed, otherwise just run
`pip install conan` or download it [here](https://conan.io/downloads).


Now run `conan profile detect --force` to have conan provide the configuration for you, of course you will need a c++ compiler.


After that, run `conan install . --output-folder=build --build=missing` in the same place as conanfile.txt is.


Everything should work! :)

