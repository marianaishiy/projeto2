#ifndef CORRELACAO_H
#define CORRELACAO_H

double covariancia(double amostra_x[], double amostra_y[], int n, int *erro);
double correlacao(double amostra_x[], double amostra_y[], int n, int *erro);
double coeficiente_linear_regressao(double amostra_x[], double amostra_y[], int n, int *erro);

#endif

