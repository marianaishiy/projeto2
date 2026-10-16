# lib_estat

Biblioteca em C para Variáveis Aleatórias que inclui cálculo de: esperança, variância, distribuições de probabilidade e correlação.

## Módulos

- **esperanca**: esperança de Binomial, Geométrica, Uniforme e Poisson
- **variancia_modelos**: variância de Binomial, Geométrica, Uniforme e Poisson
- **distribuicoes**: probabilidade (discretas) e densidade(uniforme)
- **correlacao**: covariância, correlação e coeficiente linear (amostras)

## Convenção de erro

Funções que podem falhar recebem 'int *erro' como último parâmetro. O ponteiro **nunca pode ser NULL**. Em sucesso, '*erro = ESTAT_OK', caso contrário, recebe um dos códigos de 'erros.h'.
