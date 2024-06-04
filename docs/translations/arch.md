# Design

A parte principal da biblioteca são as funções no header "specialized_functions.h", e o nome do header não é à toa.
Basicamente, o tipo `MatrixType` é um alias para o contêiner array da STL do C++. Vamos entender.


```c++
//tipo
using MatrixType = std::array<std::array<TypeSpecialization, COLS>, ROWS>;

//Primeiramente, é declarado um std::array que recebe um tipo specializado, mas podemos simplificar tirando os namespaces// Primeiramente, é declarado um std::array que recebe um tipo especializado, mas podemos simplificar tirando os namespaces
// para ficar mais claro
array(primeiro array)<(tipo do array)array<TypeSpecialization(Tipo genérico), (tamanho do tipo do Array)COLS>, (Tamanho do primeor array)Rows>;
```

Assim, é garantido que todas as funções apresentadas dentro do header sofram a especialização dos três tipos disponíveis
int, double, `bool::rational<int>` que é o tipo `Rational` que também foi abstraido usando type alias.

Assim, permitindo que todos os tipos sejam aceitos e as funções tenho assinaturas iguais, apenas mudando o tipo.

A classe `Matrix` é apenas um wrapper das funções, caso vocẽ queira algo mais centralizado e queira evitar funções soltas.

As funções em sua maioria centralizadas
você pode optar por usar a classe. A única função que não tem implementação na classe é `determinant()`, mas isso será discutido depois.


Da mesma forma que as funções, a classe `Matrix` confia em especialização, é uma classe genérica base e depois cada tipo recebe
sua especialização.


Caso queira saber mais sobre especialização, pode ler [Esse Artigo da referência do C++](https://en.cppreference.com/w/cpp/language/template_specialization)

No fim, buscamos a simplicidade e o jeito mais intuitivo de ser feito, usando as abstrações disponíveis.

# Convenções

Aqui falaremos sobre a padronização dos conteúdos da biblioteca.


### Namespaces

A convenção seguida foi a seguinte: para as funções, será usado o namespace `mtx_f`, que é a abreviação de `matrix_function`, 
e para a classe, que como visto anteriormente é apenas um wrapper das funções concentradas em um tipo, é `mtx`, 
que é uma abreviação para matrix.


### Pastas

Em relação aos arquivos, a biblioteca, por ser uma classe e funções especializadas, o compilador acaba perdendo a referência e isso tornou a biblioteca "header only", então tudo fica dentro da pasta `include` e não há pasta `src`. Dessa forma, caso seja necessário, você pode só extrair um dos headers e deixar o outro dentro da pasta include.


### Type Alias

Como discutido anteriormente, alguns tipos são apenas alias. Optei por deixar dessa forma porque alguns tipos são extremamente verbosos e propensos a erros, por exemplo, `MatrixType` é um array 2D, mas a sintaxe de sua declaração não ajuda muito. Então fica bem mais agradável só digitar `MatrixType<Tipo, ...(Ordem do template vigente)>`.

A mesma coisa vale para o tipo `Rational`, ele usa um int, abstraindo o usuário de lidar com ele, o tipo tem que apenas ser posto e pronto para usar.

### Dependências

As dependências são gerenciadas pelo `Conan`, um `package manager` de C++. Então, tendo ele, você pode usar tranquilamente. Inicialmente foi adotado o esquema do CLion, mas por simplicidade provemos apenas o conanfile.txt, já que você pode ter a biblioteca compilada e querer usar apenas o CMake sem precisar usar o Conan.

Quanto aos tipos, os tipos são redefinidos no seu namespace para evitar confusão, então tudo que é usado em um namespace é usado lá e não herdado do outro namespace, assim evitando ter que incluir mais de uma dependência.

# Mais

Algumas dúvidas podem ter ficado em aberto, como por exemplo:

- Por que a função determinant() não está na classe?
- Por que especialização?

Acaba que isso é uma pergunta mais genérica, então serão respondidas no FAQ. :)