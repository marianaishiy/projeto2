#ifndef DISTRIBUICOES_H
#define DISTRIBUICOES_H

#include "erros.h"

/**
 * @brief Calcula P(X = k) para X ~ Binomial(n, p).
 * @param k Quantidade de sucessos.
 * @param n Quantidade de ensaios.
 * @param p Probabilidade de sucesso em cada ensaio (0 <= p <= 1).
 * @param erro Ponteiro onde o codigo de erro sera escrito (ESTAT_OK em sucesso).
 * @return P(X = k), ou 0.0 em caso de erro. Retorna 0.0 valido se k > n.
 * @note *erro = ESTAT_ERRO_N_INVALIDO se n <= 0 ou k < 0.
 * @note *erro = ESTAT_ERRO_PARAMETRO_INVALIDO se p fora de [0,1].
 */
double probabilidade_binomial(int k, int n, double p, int *erro);

/**
 * @brief Calcula P(X = k) para X ~ Geometrica(p), com k fracassos antes do primeiro sucesso.
 * @param k Quantidade de fracassos antes do sucesso.
 * @param p Probabilidade de sucesso (0 < p <= 1).
 * @param erro Ponteiro onde o codigo de erro sera escrito.
 * @return P(X = k), ou 0.0 em caso de erro.
 * @note *erro = ESTAT_ERRO_N_INVALIDO se k < 0.
 * @note *erro = ESTAT_ERRO_PARAMETRO_INVALIDO se p <= 0 ou p > 1.
 */
double probabilidade_geometrica(int k, double p, int *erro);

/**
 * @brief Calcula P(X = k) para X ~ Poisson(lambda).
 * @param k Quantidade de ocorrencias no intervalo.
 * @param lambda Taxa de ocorrencia (lambda > 0).
 * @param erro Ponteiro onde o codigo de erro sera escrito.
 * @return P(X = k), ou 0.0 em caso de erro.
 * @note *erro = ESTAT_ERRO_N_INVALIDO se k < 0.
 * @note *erro = ESTAT_ERRO_PARAMETRO_INVALIDO se lambda <= 0.
 */
double probabilidade_poisson(int k, double lambda, int *erro);

/**
 * @brief Calcula a densidade f(x) de X ~ Uniforme(a, b).
 * @param x Ponto onde a densidade e avaliada.
 * @param a Limite inicial do intervalo.
 * @param b Limite final do intervalo.
 * @param erro Ponteiro onde o codigo de erro sera escrito.
 * @return 1/(b-a) se a <= x <= b; 0.0 fora do intervalo (retorno valido, nao e erro).
 * @note *erro = ESTAT_ERRO_PARAMETRO_INVALIDO se a >= b.
 * @note f(x) e densidade, nao probabilidade pontual (P(X = x) = 0).
 */
double densidade_uniforme(double x, double a, double b, int *erro);

#endif
