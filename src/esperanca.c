#include <stdio.h>
#include "esperanca.h"
#include "erros.h"

double esperanca_binomial (int n, double p, int *erro) {

    /* n é o número de ensaios e p a probabilidade de sucesso*/

    if (n <= 0) {
        *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }

    if (p < 0 || p > 1) {
        *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    *erro = ESTAT_OK;
    return n*p;

}

double esperanca_geometrica (double p, int *erro) {

    /* p é a probabilidade de sucesso*/

    if (p < 0 || p > 1) {
        *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }
    if(p == 0) {
        *erro =  ESTAT_ERRO_DIVISAO_ZERO;
        return 0.0;
    }

    *erro = ESTAT_OK;
    return (1-p)/p;

}

double esperanca_uniforme (double a, double b, int *erro) {

    /*[a,b] é o intervalo de valores que a variável aleatória pode assumir*/

    if (a >= b) {
        *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    *erro = ESTAT_OK;
    return (a + b)/2;
}

double esperanca_poisson (double lambda, int *erro) {

    /* lambda é a taxa média de ocorrência do evento raro num intervalo*/

    if (lambda <= 0) {
        *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    *erro = ESTAT_OK;
    return lambda;
}




