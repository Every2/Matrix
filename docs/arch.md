[PT-BR](translations/arch.md)

# Design

The main part of the library consists of the functions in the "specialized_functions.h" header, and the name of the header is not without reason.

Basically, the type `MatrixType` is an alias for the C++ STL array container. Let's understand.

```c++
// type
using MatrixType = std::array<std::array<TypeSpecialization, COLS>, ROWS>;

// First, a std::array is declared that receives a specialized type, but we can simplify by removing the namespaces
// to make it clearer
array(first array)<(type of the array)array<TypeSpecialization(generic type), (size of the array type)COLS>, (Size of the first array)Rows>;
```

Thus, it is guaranteed that all functions presented within the header undergo specialization for the three available types: int, double, and bool::rational<int>, which is the type Rational that was also abstracted using type alias.

This allows all types to be accepted, and the functions have identical signatures, only changing the type.

The Matrix class is merely a wrapper for the functions, in case you want something more centralized and want to avoid loose functions.

The functions, mostly centralized, so you can choose to use the class. The only function that does not have an implementation in the class is determinant(), but this will be discussed later.

Just like the functions, the Matrix class relies on specialization, being a base generic class and then each type receives its specialization.

If you want to learn more about specialization, you can read [this article from the C++ reference](https://en.cppreference.com/w/cpp/language/template_specialization).

In the end, we seek simplicity and the most intuitive way to do things, using the available abstractions.

# Conventions

Here we will talk about standardizing the contents of the library.

### Namespaces

The convention followed was as follows: for functions, the namespace `mtx_f` will be used, which is an abbreviation for matrix_function, 
and for the class, which as seen earlier is just a wrapper for the functions concentrated in one type, it is `mtx`, which is an abbreviation for matrix.

### Folders

Regarding the files, the library, being a class and specialized functions, the compiler ends up losing the reference, making 
the library header only, so everything is inside the include `folder` and there is no `src` folder. Thus, if necessary, 
you can simply extract one of the headers and leave the other inside the include folder.

### Type Alias

As discussed earlier, some types are just aliases. I chose to leave it this way because some types are extremely verbose 
and error-prone, for example, `MatrixType` is a 2D array, but its declaration syntax is not very helpful. So it's much nicer 
to just type `MatrixType<Type, ...(Order of the current template)>`.

The same goes for the type `Rational`, it uses an `int`, abstracting the user from dealing with it, the type just needs to be put and ready to use.


### Dependencies

Dependencies are managed by `Conan`, a C++ package manager. So, having it, you can use it easily. Initially, the CLion scheme was adopted, 
but for simplicity, we provide only the `conanfile.txt`, since you can have the library compiled and just want to use CMake without needing Conan.

As for the types, they are redefined in their namespace to avoid confusion, so everything used in one namespace is used there 
and not inherited from the other namespace, thus avoiding having to include more than one dependency.

# More

Some questions may have remained open, such as:

- Why isn't the `determinant()` function in the class?
- Why specialization?

This ends up being a more generic question, so they will be answered in the FAQ. :)