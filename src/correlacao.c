#include "correlacao.h"
#include "erros.h"
#include <stddef.h>

double covariancia(double amostra_x[], double amostra_y[], int n, int *erro) {
    if (erro != NULL) *erro = ESTAT_OK;
    if (n <= 1) {
        if (erro != NULL) *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }
    return 0.0;
}

double correlacao(double amostra_x[], double amostra_y[], int n, int *erro) {
    if (erro != NULL) *erro = ESTAT_OK;
    if (n <= 1) {
        if (erro != NULL) *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }
    return 0.0;
}

double coeficiente_linear_regressao(double amostra_x[], double amostra_y[], int n, int *erro) {
    if (erro != NULL) *erro = ESTAT_OK;
    if (n <= 1) {
        if (erro != NULL) *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }
    return 0.0;
}
