#ifndef VARIANCIA_MODELOS_H
#define VARIANCIA_MODELOS_H


#include "erros.h"

/**
 * @file variancia_modelos.h
 * @brief Módulo de Cálculo de Variância.
 */

/**
 * @brief Função que calcula a variância de uma distribuição binomial
 *
 *
 * @param n Parâmentro n que diz a quantidade de ensaios independetes da distribuição binomial
 * @param p Parâmetro p que diz a probabilidade de sucesso em cada ensaio independente da binomial
 * @param erro Ponteiro para onde o código de erro será escrito
 *             (ESTAT_OK em caso de sucesso).
 *
 * @return A função retorna a variância da binomial ou 0.0 em caso
 *         de erro (verificar *erro para o motivo).
 *
 * @note Define *erro = ESTAT_ERRO_N_INVALIDO se n <= 0.
 * @note Define *erro = ESTAT_ERRO_PARAMETRO_INVALIDO se p fora de [0,1].
 */
double variancia_binomial(int n, double p, int *erro);

/**
 * @brief Função que calcula a variância de uma distribuição geometrica
 *
 *
 * @param p Parâmetro p que diz a probabilidade de ocorrência do evento desejado
 * @param erro Ponteiro para onde o código de erro será escrito
 *             (ESTAT_OK em caso de sucesso).
 *
 * @return A função retorna a variância da geométrica ou 0.0 em caso
 *         de erro (verificar *erro para o motivo).
 *
 * @note Define *erro = ESTAT_ERRO_DIVISAO_ZERO se p=0
 * @note Define *erro = ESTAT_ERRO_PARAMETRO_INVALIDO se p fora de [0,1].
 */
double variancia_geometrica(double p, int *erro);

/**
 * @brief Função que calcula a variância de uma distribuiçao de variáveis contínuas em um intervalo
 *
 *
 * @param a Menor número do intervalo 
 * @param b Maior número do intervalo 
 * @param erro Ponteiro para onde o código de erro será escrito
 *             (ESTAT_OK em caso de sucesso).
 *
 * @return A função retorna a variância da uniforme ou 0.0 em caso
 *         de erro (verificar *erro para o motivo).
 *
 * @note A distribuição é para variáveis contínuas em um intervalo [a,b].
 * @note Define *erro=ESTAT_ERRO_PARAMETRO_INVALIDO se a>=b.
 */
double variancia_uniforme(double a, double b, int *erro);


/**
 * @brief Função que calcula a variância de uma distribuição Poisson
 *
 *
 * @param lambda Parametro lambda que diz a taxa de ocorrência do evento que se deseja modelar
 * @param erro Ponteiro para onde o código de erro será escrito
 *             (ESTAT_OK em caso de sucesso).
 *
 * @return A função retorna a variância da Poisson ou 0.0 em caso
 *         de erro (verificar *erro para o motivo).
 *
 * @note Define *erro=ESTAT_ERRO_PARAMETRO_INVALIDO se lambda<=0
 */
double variancia_poisson(double lambda, int *erro);




#endif
