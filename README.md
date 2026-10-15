# lib_estat
## Introdução
A biblioteca `lib_estat` é uma biblioteca em C criada para facilitar o cálculo de variáveis aleatórias e seu modelos de probabilidade, com as estatísticas de cada modelo, como Modelo de Poisson, modelo Binomial, modelo Uniforme, Modelo Geométrico. A biblioteca contém 15 funções públicas as quais estão distribuídas em 4 módulos.

A biblioteca contém, enbutida em sua compilação, a opção de compilá-la estaticamente ou dinamicamente.

## Módulos
| Módulo | Funções |
|--------|---------|
| `esperanca` | `esperanca_binomial`, `esperanca_geometrica`, `esperanca_uniforme`,`esperanca_poisson ` |
| `variancia_modelos` | `variancia_binomial`, `variancia_geometrica`, `variancia_uniforme`, `variancia_poisson` |
|`distribuicoes`|`probabilidade_binomial`,`probabilidade_geometrica`,`probabilidade_poisson`,`densidade_uniforme`|
|`correlacao`|`covariancia`,`correlacao`,`coeficiente_linear`|

## Pré-requisitos
É necessário, para compilar e utilizar a biblioteca os seguintes pré-requisitos:
-Make
-Doxygen para documentação
-Gdb

## Estrutura 
```text
./
├── .gitignore
├── .vscode/
│   └── settings.json
├── Doxyfile
├── Makefile
├── README.md
├── app/
│   └── main.c
├── bin/
│   ├── .gitkeep
│   └── app_teste*
├── build/
│   └── .gitkeep
├── docs/
│   ├── .gitkeep
│   └── relatorio/
│       └── relatorio.tex
├── include/
│   ├── correlacao.h
│   ├── distribuicoes.h
│   ├── erros.h
│   ├── esperanca.h
│   └── variancia_modelos.h
├── lib/
│   └── .gitkeep
├── relatorio.out
├── src/
│   ├── correlacao.c
│   ├── distribuicoes.c
│   ├── esperanca.c
│   └── variancia_modelos.c
└── tests/
    ├── test_distribuicoes.c
    └── test_variancia_modelos.c
```

## Convenção de erro

Funções que podem falhar recebem 'int *erro' como último parâmetro. O ponteiro **nunca pode ser NULL**. Em sucesso, '*erro = ESTAT_OK', caso contrário, recebe um dos códigos de 'erros.h'.
