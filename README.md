# lib_estat
## Introdução
A biblioteca `lib_estat` é uma biblioteca em C criada para facilitar o cálculo de variáveis aleatórias e seus modelos de probabilidade, como modelo de Poisson, modelo Binomial, modelo Uniforme, modelo Geométrico. Além dos modelos, a biblioteca também calcula as estatísticas provenientes de cada modelo. A biblioteca contém 15 funções públicas as quais estão distribuídas em 4 módulos.

A biblioteca contém, embutida em sua compilação, a opção de compilá-la estaticamente ou dinamicamente. Para a biblioteca estática, cria-se  `liblib_estat.a`, para a biblioteca dinâmica: `liblib_estat.so`.

## Módulos
| Módulo | Funções |
|--------|---------|
| `esperanca` | `esperanca_binomial`, `esperanca_geometrica`, `esperanca_uniforme`,`esperanca_poisson`|
| `variancia_modelos` | `variancia_binomial`, `variancia_geometrica`, `variancia_uniforme`, `variancia_poisson` |
|`distribuicoes`|`probabilidade_binomial`,`probabilidade_geometrica`,`probabilidade_poisson`,`densidade_uniforme`|
|`correlacao`|`covariancia`,`correlacao`,`coeficiente_linear_regressao`|


## Pré-requisitos
É necessário, para compilar e utilizar a biblioteca os seguintes pré-requisitos:
- Sistema Operacional Linux
- Make
- Compilador `gcc`
- Doxygen para documentação (opcional)
- Gdb (opcional)

## Estrutura 
```text
./
├── Doxyfile
├── Makefile
├── README.md
├── app/ (contém o appclient, a aplicação que demonstra a utilização do programa)
│   └── main.c
├── bin/
│   └── .gitkeep
├── build/ (contém arquivos intermediários de compilação, como .o (arquivo objeto))
│   └── .gitkeep
├── docs/(onde fica a documentação e a saída do Doxygen)
│   ├── .gitkeep
│   └── relatorio/
│       └── relatorio.tex
├── include/ (contém as assinaturas e interfaces da biblioteca)
│   ├── correlacao.h
│   ├── distribuicoes.h
│   ├── erros.h
│   ├── esperanca.h
│   └── variancia_modelos.h
├── lib/(após a compilação, onde as bibliotecas estática .a e dinâmica .so estarão)
│   └── .gitkeep
├── src/(contém a implementação das funções da biblioteca)
│   ├── correlacao.c
│   ├── distribuicoes.c
│   ├── esperanca.c
│   └── variancia_modelos.c
└── tests/
    ├── test_distribuicoes.c
    └── test_variancia_modelos.c
```

## Convenção de erro
| Código | Valor | Quando ocorre |
|--------|-------|---------------|
| `ESTAT_OK` | 0|Quando não há nenhum erro |
|`ESTAT_ERRO_N_INVALIDO`|1|Quando o tamanho da amostra é inválido (valores menores que 1)|
|`ESTAT_ERRO_TAMANHOS_DIFERENTES`|2|Está reservado, mas nenhuma função utiliza|
|`ESTAT_ERRO_DIVISAO_ZERO`|3|Quando ocorre uma divisão por 0, por causa da `variancia_geometrica`, com p==0|
|`ESTAT_ERRO_PARAMETRO_INVALIDO`|4|Quando o parâmetro utilizado não é válido, como p fora de [0,1]|

Utiliza-se o ponteiro `*erro` para atribuir o código de retorno de cada função. Caso a função tenha sucesso, o valor de `*erro`=`ESTAT_OK`. Em caso de erro, a função retornará 0.0 e deve-se checar o parâmetro `*erro` para que veja o motivo. O ponteiro nunca pode ser `NULL`.

## Exemplos de Uso

Exemplo de programa que calcula a variância binomial 

```c
#include <stdio.h>
#include "variancia_modelos.h"
#include "erros.h"

int main(void)
{
    int erro;
    double resultado;

    /* Caso válido */
    resultado = variancia_binomial(10,0.5, &erro);
    if (erro == ESTAT_OK) {
        printf("passou = %f\n", resultado);
    } else {
        printf("erro: %d\n", erro);
    }

    /* Caso inválido */
    resultado = variancia_binomial(0, 0.5, &erro);
    if (erro == ESTAT_OK) {
        printf("passou = %f\n", resultado);
    } else {
        printf("erro: %d\n", erro);
    }

    return 0;
}
```

Saída esperada:

```text
passou = 2.500000
erro: 1
```

## Doxygen


