#include <stdio.h>
#include <assert.h>
#include "esperanca.h"
#include <math.h>

static int quase_igual(double a, double b) { 
  return fabs(a - b) < 1e-9; 
}

void test_esperanca_binomial_n_invalido(void) {

    int erro = ESTAT_OK;
    double esperanca = esperanca_binomial(0, 0.5, &erro);
    assert (erro == ESTAT_ERRO_N_INVALIDO);
    assert (esperanca == 0.0);

    erro = ESTAT_OK;
    esperanca = esperanca_binomial(-1, 0.5, &erro);
    assert (erro == ESTAT_ERRO_N_INVALIDO);
    assert (esperanca == 0.0);

    printf("Passou em test_esperanca_binomial_n_invalido.\n");

}

void test_esperanca_binomial_parametro_invalido(void) {
    
    int erro = ESTAT_OK;
    double esperanca = esperanca_binomial(3, -1, &erro);
    assert (erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert (esperanca == 0.0);

    erro = ESTAT_OK;
    esperanca = esperanca_binomial(3, 1.5, &erro);
    assert (erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert (esperanca == 0.0);

    printf("Passou em test_esperanca_binomial_parametro_invalido.\n");
}

void test_esperanca_binomial_valido(void) {

    int erro = -1;
    double esperanca = esperanca_binomial(3, 0.5, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 1.5));

    erro = -1;
    esperanca = esperanca_binomial(3, 0, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 0.0));

    erro = -1;
    esperanca = esperanca_binomial(3, 1, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 3));

    printf("Passou em test_esperanca_binomial_valido.\n");
}



void test_esperanca_geometrica_parametro_invalido(void) {

    int erro = ESTAT_OK;
    double esperanca = esperanca_geometrica(0, &erro);
    assert (erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert (esperanca == 0.0);

    erro = ESTAT_OK;
    esperanca = esperanca_geometrica(-1, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert(esperanca == 0.0);

    erro = ESTAT_OK;
    esperanca = esperanca_geometrica(1.5, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert(esperanca == 0.0);

    printf("Passou em test_esperanca_geometrica_parametro_invalido.\n");
}   

void test_esperanca_geometrica_valido(void) {

    int erro = -1;
    double esperanca = esperanca_geometrica(0.5, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 2));

    erro = -1;
    esperanca = esperanca_geometrica(1, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 1));

    printf("Passou em test_esperanca_geometrica_valido.\n");

}



void test_esperanca_uniforme_parametro_invalido(void) {
    
    int erro = ESTAT_OK;
    double esperanca = esperanca_uniforme(1, 1, &erro);
    assert (erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert (esperanca == 0.0);

    erro = ESTAT_OK;
    esperanca = esperanca_uniforme(2, 1, &erro);
    assert (erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert (esperanca == 0.0);

    printf("Passou em test_esperanca_uniforme_parametro_invalido\n");

}

void test_esperanca_uniforme_valido(void) {

    int erro = -1;
    double esperanca = esperanca_uniforme(1, 2, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 1.5));

    erro = -1;
    esperanca = esperanca_uniforme(-2, 2, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 0.0));

    printf("Passou em test_esperanca_uniforme_valido.\n");

}

void test_esperanca_poisson_parametro_invalido(void) {
    int erro = ESTAT_OK;
    double esperanca = esperanca_poisson(0, &erro);
    assert (erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert (esperanca == 0.0);

    erro = ESTAT_OK;
    esperanca = esperanca_poisson(-1, &erro);
    assert (erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert (esperanca == 0.0);

    printf("Passou em test_esperanca_poisson_parametro_invalido\n");
}

void test_esperanca_poisson_valido(void) {

    int erro = -1;
    double esperanca = esperanca_poisson(1, &erro);
    assert (erro == ESTAT_OK);
    assert (quase_igual(esperanca, 1));

    printf("Passou em test_esperanca_poisson_valido.\n");

}



int main(void) {
    test_esperanca_binomial_n_invalido();
    test_esperanca_binomial_parametro_invalido();
    test_esperanca_binomial_valido();

    test_esperanca_geometrica_parametro_invalido();
    test_esperanca_geometrica_valido();

    test_esperanca_uniforme_parametro_invalido();
    test_esperanca_uniforme_valido();

    test_esperanca_poisson_parametro_invalido();
    test_esperanca_poisson_valido();

    printf("Todos os testes obtiveram sucesso!.\n");
    return 0;
}