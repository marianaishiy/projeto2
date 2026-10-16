#include "correlacao.h"
#include "erros.h"
#include <stddef.h>
#include <math.h>

double covariancia(double amostra_x[], double amostra_y[], int n, int *erro) {
    if (erro != NULL)
        *erro = ESTAT_OK;

    if (n <= 1) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }

    if (amostra_x == NULL || amostra_y == NULL) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    double soma_x = 0.0;
    double soma_y = 0.0;

    for (int i = 0; i < n; i++) {
        soma_x += amostra_x[i];
        soma_y += amostra_y[i];
    }

    double media_x = soma_x / n;
    double media_y = soma_y / n;

    double soma_produtos = 0.0;

    for (int i = 0; i < n; i++) {
        soma_produtos += (amostra_x[i] - media_x) *
                         (amostra_y[i] - media_y);
    }

    return soma_produtos / (n - 1);
}

double correlacao(double amostra_x[], double amostra_y[], int n, int *erro) {
    if (erro != NULL)
        *erro = ESTAT_OK;

    if (n <= 1) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }

    if (amostra_x == NULL || amostra_y == NULL) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    double soma_x = 0.0;
    double soma_y = 0.0;

    for (int i = 0; i < n; i++) {
        soma_x += amostra_x[i];
        soma_y += amostra_y[i];
    }

    double media_x = soma_x / n;
    double media_y = soma_y / n;

    double soma_produtos = 0.0;
    double soma_quadrados_x = 0.0;
    double soma_quadrados_y = 0.0;

    for (int i = 0; i < n; i++) {
        double desvio_x = amostra_x[i] - media_x;
        double desvio_y = amostra_y[i] - media_y;

        soma_produtos += desvio_x * desvio_y;
        soma_quadrados_x += desvio_x * desvio_x;
        soma_quadrados_y += desvio_y * desvio_y;
    }

    if (soma_quadrados_x == 0.0 || soma_quadrados_y == 0.0) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_DIVISAO_ZERO;
        return 0.0;
    }

    double denominador = sqrt(soma_quadrados_x) *
                         sqrt(soma_quadrados_y);

    return soma_produtos / denominador;
}


double coeficiente_linear_regressao(double amostra_x[], double amostra_y[], int n, int *erro) {
    if (erro != NULL)
        *erro = ESTAT_OK;

    if (n <= 1) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }

    if (amostra_x == NULL || amostra_y == NULL) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    double soma_x = 0.0;
    double soma_y = 0.0;

    for (int i = 0; i < n; i++) {
        soma_x += amostra_x[i];
        soma_y += amostra_y[i];
    }

    double media_x = soma_x / n;
    double media_y = soma_y / n;

    double soma_produtos = 0.0;
    double soma_quadrados_x = 0.0;

    for (int i = 0; i < n; i++) {
        double desvio_x = amostra_x[i] - media_x;
        double desvio_y = amostra_y[i] - media_y;

        soma_produtos += desvio_x * desvio_y;
        soma_quadrados_x += desvio_x * desvio_x;
    }

    if (soma_quadrados_x == 0.0) {
        if (erro != NULL)
            *erro = ESTAT_ERRO_DIVISAO_ZERO;
        return 0.0;
    }

    return soma_produtos / soma_quadrados_x;
}
