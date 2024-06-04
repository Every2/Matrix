# FAQ

# Por que Determinant ficou de fora da classe?

Bom, a `classe Matrix` é apenas um wrapper das funções, como explicado no documento de arquitetura. Como o determinant seria o único método estático, 
você não usaria nada da classe em si. Portanto, optei por deixá-lo de fora. Se quiser usar a função, não precisa da classe, 
pode apenas criar seu array e usar na função. E se, por algum motivo, precisar da classe, você pode reutilizar o array, 
passando-o para o construtor da classe.

# Por que especialização?

Simples, por simplicidade. Queria deixar este projeto o mais simples possível. Inicialmente, foi cogitado usar três construtores. 
E como o projeto já tem um design pré-estabelecido, a especialização se torna um bom design, já que os métodos/funções são centralizados, 
mas desacoplados, e não será adicionado nenhum novo. E se for, podemos apenas usar uma função especializada e adicioná-la na classe. :)

Outro fator é que a alternativa de std::variant ficaria muito complexa, apesar de ser melhor para manutenção, e traria 
muito mais overheads, o que não é o intuito do projeto.

# Qual a versão do C++ do projeto?

Sendo sincero, acho que você pode usar qualquer padrão a partir do 11. Eu utilizei o 20, mas não vejo nada que você não possa usar nas versões mais antigas.

Para isso, você pode alterar a versão no CMake.

`set(CMAKE_CXX_STANDARD 20)`


# Por que os templates são diferentes no tipo e nas funções?

No tipo, foi priorizada a notação matemática, que é coluna-linhas, e nas funções, a notação computacional, que é mais intuitiva, 
que é linha-coluna. Dessa forma, a primeira facilita a escrita de constantes para as matrizes. Por exemplo:


```c++
///Matriz
1 2 3
4 5 6

MatrixType<int, 2, 3> matrix {{
  {1, 2, 3},
  {4, 5, 6},
}};

```
