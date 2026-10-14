#ifndef CORRELACAO_H
#define CORRELACAO_H

/**
 * @file correlacao.h
 * @brief Módulo de Correlação e Regressão Linear.
 */

/**
 * @brief Calcula a covariância amostral entre duas variáveis contínuas.
 * @param amostra_x Array com os valores da primeira amostra.
 * @param amostra_y Array com os valores da segunda amostra.
 * @param n Tamanho dos arrays (deve ser maior que 1).
 * @param erro Ponteiro onde será armazenado o código de erro da operação.
 * @return Valor da covariância amostral calculada.
 */
double covariancia(double amostra_x[], double amostra_y[], int n, int *erro);

/**
 * @brief Calcula o coeficiente de correlação de Pearson entre duas variáveis.
 * @param amostra_x Array com os valores da primeira amostra.
 * @param amostra_y Array com os valores da segunda amostra.
 * @param n Tamanho dos arrays (deve ser maior que 1).
 * @param erro Ponteiro onde será armazenado o código de erro da operação.
 * @return Valor da correlação de Pearson (-1.0 a 1.0).
 */
double correlacao(double amostra_x[], double amostra_y[], int n, int *erro);

/**
 * @brief Calcula o coeficiente de regressão linear simples.
 * @param amostra_x Array com os valores da variável independente.
 * @param amostra_y Array com os valores da variável dependente.
 * @param n Tamanho dos arrays (deve ser maior que 1).
 * @param erro Ponteiro onde será armazenado o código de erro da operação.
 * @return Valor do coeficiente de regressão linear.
 */
double coeficiente_linear_regressao(double amostra_x[], double amostra_y[], int n, int *erro);

#endif



















