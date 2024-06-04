# FAQ

[PT-BR](docs/translations/FAQ.md)

# Why was the Determinant left out of the class?

Well, the `Matrix class` is just a wrapper for the functions, as explained in the architecture document. Since the determinant 
would be the only static method, you wouldn't use anything from the class itself. So, I chose to leave it out. 
If you want to use the function, you don't need the class, you can just create your array and use it in the function. 
And if, for some reason, you need the class, you can reuse the array by passing it to the class constructor.

# Why specialization?

Simple, for simplicity. I wanted to make this project as simple as possible. Initially, using three constructors was considered. 
And since the project already has a pre-established design, specialization becomes a good design, since the methods/functions are centralized, 
but decoupled, and no new ones will be added. And if so, we can just use a specialized function and add it to the class. :)

Another factor is that the alternative of `std::variant` would be too complex, although it would be better for maintenance 
and would bring much more overhead, which is not the intention of the project.

# What is the C++ version of the project?

To be honest, I think you can use any standard from 11 onwards. I used 20, but I don't see anything that you couldn't use in older versions.

To do this, you can change the version in CMake.

`set(CMAKE_CXX_STANDARD 20)`

# Why are the templates different in the type and in the functions?

In the type, mathematical notation was prioritized, which is column-rows, and in the functions, computational notation, 
which is more intuitive, which is row-column. This way, the former facilitates writing constants for matrices. For example:

```c++
///Matrix
1 2 3
4 5 6

MatrixType<int, 2, 3> matrix {{
  {1, 2, 3},
  {4, 5, 6},
}};

```