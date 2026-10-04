#include "variancia_modelos.h"

double variancia_binomial(int n, double p, int *erro){
    if (n <= 0) {
        *erro = ESTAT_ERRO_N_INVALIDO;
        return 0.0;
    }
    if (p < 0 || p > 1) {
        *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    *erro = ESTAT_OK;
    return n*p*(1-p);

}
double variancia_geometrica(double p, int *erro){
    if (p<0 || p>1){
        *erro=ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }
    if(p==0){
        *erro=ESTAT_ERRO_DIVISAO_ZERO;
        return 0.0;
    }
    *erro=ESTAT_OK;
    return (1-p)/(p*p);
}
double variancia_uniforme(double a, double b, int *erro){
    if (a>=b) {
        *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }

    *erro = ESTAT_OK;
    return ((b-a)*(b-a))/12;
}

double variancia_poisson(double lambda, int *erro){
    if (lambda <= 0) {
        *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
        return 0.0;
    }
    *erro = ESTAT_OK;
    return lambda;
}
