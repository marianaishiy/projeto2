
#ifndef CORRELACAO_H
#define CORRELACAO_H

#include "erros.h"

/**
 * @file correlacao.h
 * @brief Modulo de correlacao e regressao linear.
 *
 * Funcoes para analise estatistica de duas amostras observadas.
 */

/**
 * @brief Calcula a covariancia amostral entre duas variaveis.
 *
 * @param amostra_x Array com os valores da primeira amostra.
 * @param amostra_y Array com os valores da segunda amostra.
 * @param n Numero de observacoes em cada amostra (n > 1).
 * @param erro Ponteiro para armazenar o codigo de erro.
 *
 * @return Valor da covariancia amostral.
 *         Retorna 0.0 em caso de erro.
 *
 * @note ESTAT_OK: calculo realizado com sucesso.
 * @note ESTAT_ERRO_N_INVALIDO: n menor ou igual a 1.
 * @note ESTAT_ERRO_PARAMETRO_INVALIDO: algum array e NULL.
 * @note Se erro for NULL, nenhum codigo de erro sera armazenado.
 */
double covariancia(double amostra_x[], double amostra_y[], int n, int *erro);

/**
 * @brief Calcula o coeficiente de correlacao de Pearson.
 *
 * Mede a intensidade e a direcao da relacao linear
 * entre duas variaveis observadas.
 *
 * @param amostra_x Array com os valores da primeira amostra.
 * @param amostra_y Array com os valores da segunda amostra.
 * @param n Numero de observacoes em cada amostra (n > 1).
 * @param erro Ponteiro para armazenar o codigo de erro.
 *
 * @return Coeficiente de Pearson no intervalo [-1.0, 1.0].
 *         Retorna 0.0 em caso de erro.
 *
 * @note ESTAT_OK: calculo realizado com sucesso.
 * @note ESTAT_ERRO_N_INVALIDO: n menor ou igual a 1.
 * @note ESTAT_ERRO_PARAMETRO_INVALIDO: algum array e NULL.
 * @note ESTAT_ERRO_DIVISAO_ZERO: variancia de X ou Y igual a zero.
 * @note Se erro for NULL, nenhum codigo de erro sera armazenado.
 */
double correlacao(double amostra_x[], double amostra_y[], int n, int *erro);

/**
 * @brief Calcula o coeficiente angular da regressao linear simples.
 *
 * Calcula a inclinacao da reta de regressao de Y em funcao de X
 * pelo metodo dos minimos quadrados.
 *
 * @param amostra_x Array com os valores da variavel independente (X).
 * @param amostra_y Array com os valores da variavel dependente (Y).
 * @param n Numero de observacoes em cada amostra (n > 1).
 * @param erro Ponteiro para armazenar o codigo de erro.
 *
 * @return Coeficiente angular da reta de regressao.
 *         Retorna 0.0 em caso de erro.
 *
 * @note ESTAT_OK: calculo realizado com sucesso.
 * @note ESTAT_ERRO_N_INVALIDO: n menor ou igual a 1.
 * @note ESTAT_ERRO_PARAMETRO_INVALIDO: algum array e NULL.
 * @note ESTAT_ERRO_DIVISAO_ZERO: variancia de X igual a zero.
 * @note Se erro for NULL, nenhum codigo de erro sera armazenado.
 */
double coeficiente_linear_regressao(double amostra_x[], double amostra_y[], int n, int *erro);

#endif
