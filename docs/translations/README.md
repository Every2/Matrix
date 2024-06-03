# MATRIX


Matrix é uma biblioteca header-only com algumas operações em matrizes que são usadas em algebra linear;


### Dependencias

Matrix tem duas dependencias:

- Google Test - Para teste, caso você queira roda-los.
- Boost Rational  - Pro tipo racional

Para essas duas dependencias, foi provido um conanfile.txt para facilitar o processo.


### Como rodar


Primeiramente, você tem que ter o conan instalado, se não apenas rode:
`pip install conan` ou baixe [aqui](https://conan.io/downloads).


Agore rode `conan profile detect --force` para o conan providenciar uma configuração para você, você tem que ter um compilador de c++ instalado.


Depois disso, rode `conan install . --output-folder=build --build=missing` no mesmo lugar que seu conanfile.txt está instalado.


Tudo deve funcionar! :)

