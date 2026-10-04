#ifndef ESPERANCA_H
#define ESPERANCA_H

#include "erros.h"

/**
 * @brief Calcula a esperança de uma variável aleatória que segue a distribuição binomial.
 * @param n Número de ensaios (n > 0).
 * @param p Probabilidade de sucesso em cada ensaio (0 <= p <= 1).
 * @param erro Ponteiro em que o código de erro será escrito (caso não dê erros teremos ESTAT_OK)
 * @return A esperança (n * p) ou 0.0 em caso de erro.
 * @note Atribuimos ao ponteiro erro ESTAT_ERRO_N_INVALIDO se n <= 0.
 * @note Atribuimos ao ponteiro erro ESTAT_ERRO_PARAMETRO_INVALIDO se p estiver fora de do intervalo [0,1].
 */
 double esperanca_binomial (int n, double p, int *erro);

/**
 * @brief Calcula a esperança de uma variável aleatória com distribuição geométrica.
 * @param p Probabilidade de sucesso em cada ensaio (0 < p <= 1).
 * @param erro Ponteiro em que o código de erro será escrito (caso não dê erros teremos ESTAT_OK)
 * @return A esperança (1/p) ou 0.0 em caso de erro.
 * @note Atribuimos ao ponteiro erro ESTAT_ERRO_PARAMETRO_INVALIDO se p for menor ou igual a zero ou maior que 1.
 */
 double esperanca_geometrica (double p, int *erro);

/**
 * @brief Calcula a esperança de uma variável aleatória com distribuição uniforme que admite valores no intervalo [a,b].
 * @param a Limite inferior do intervalo de valores que a variável aleatória pode assumir.
 * @param b Limite superior do intervalo de valores que a variável aleatória pode assumir.
 * @param erro Ponteiro em que o código de erro será escrito (caso não dê erro teremos ESTAT_OK)
 * @return A esperança ((a+b)/2) ou 0.0 em caso de erro.
 * @note Atribuimos ao ponteiro erro ESTAT_ERRO_PARAMETRO_INVALIDO se a >= b
 */
 double esperanca_uniforme (double a, double b, int *erro);

/**
 * @brief Calcula a esperança de uma variável aleatória com distribuição de Poisson.
 * @param lambda Taxa média de ocorrência do evento raro num intervalo determinado.
 * @param erro Ponteiro em que o código de erro será escrito (caso não dê erro teremos ESTAT_OK)
 * @return A esperança (lambda) ou 0.0 em caso de erro.
 * @note Atribuimos ao ponteiro erro ESTAT_ERRO_PARAMETRO_INVALIDO se lambda for menor ou igual a zero.
 */
 double esperanca_poisson (double lambda, int *erro);

#endif