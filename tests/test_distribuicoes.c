#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "distribuicoes.h"

static int quase_igual(double a, double b) { 
  return fabs(a - b) < 1e-9; 
}

void test_probabilidade_binomial_p_invalida(void) {
    int erro = ESTAT_OK;
    double prob = probabilidade_binomial(1, 3, -1.0, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_binomial_p_invalida\n");
}

void test_probabilidade_binomial_n_invalido(void) {
    int erro = ESTAT_OK;
    double prob = probabilidade_binomial(1, -1, 1.0, &erro);
    assert(erro == ESTAT_ERRO_N_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_binomial_n_invalido\n");
}
// k < 0
void test_probabilidade_binomial_k_menor_que_zero(void) {
    int erro = ESTAT_OK;
    double prob = probabilidade_binomial(-1, 3, 0.5, &erro);
    assert(erro == ESTAT_ERRO_N_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_binomial_k_menor_que_zero\n");
}

void test_probabilidade_binomial_k_maior_que_n(void){
  int erro = -1;
  double prob = probabilidade_binomial(4, 3, 0.5, &erro);
  assert(erro == ESTAT_OK);
  assert(prob == 0);
  printf("[passou] test_probabilidade_binomial_k_maior_que_n\n");
}

void test_probabilidade_binomial_n_zero(void){
  int erro = ESTAT_OK;
  double prob = probabilidade_binomial(0, 0, 0.5, &erro);
  assert(erro == ESTAT_ERRO_N_INVALIDO);
  assert(prob == 0.0);
  printf("[passou] test_probabilidade_binomial_n_zero\n");
}
void test_probabilidade_binomial_valida(void) {
    int erro = -1;
    /* P(X=1), n=3, p=0.5 -> 3 * 0.5^3 = 0.375 */
    double prob = probabilidade_binomial(1, 3, 0.5, &erro);
    assert(erro == ESTAT_OK);
    assert(quase_igual(prob, 0.375));
    printf("[passou] test_probabilidade_binomial_valida\n");
}

void test_probabilidade_geometrica(void) {
    int erro = -1;
    double prob = probabilidade_geometrica(2, 0.5, &erro); /* 0.5 * 0.25 */
    assert(erro == ESTAT_OK);
    assert(quase_igual(prob, 0.125));
    probabilidade_geometrica(0, 0.0, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    printf("[passou] test_probabilidade_geometrica\n");
}

void test_probabilidade_geometrica_p_invalida(void) {
    int erro = -1;
    double prob = probabilidade_geometrica(2, -0.5, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_geometrica_p_invalida\n");
}
// k < 0
void test_probabilidade_geometrica_k_invalido(void) {
    int erro = -1;
    double prob = probabilidade_geometrica(-1, 0.5, &erro);
    assert(erro == ESTAT_ERRO_N_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_geometrica_k_invalido\n");
}

void test_probabilidade_poisson(void) {
    int erro = -1;
    double prob = probabilidade_poisson(0, 2.0, &erro); /* e^-2 */
    assert(erro == ESTAT_OK);
    assert(quase_igual(prob, exp(-2.0)));
    probabilidade_poisson(1, -1.0, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    printf("[passou] test_probabilidade_poisson\n");
}

void test_probabilidade_poisson_lambda_invalido(void){
  int erro = -1;
  double prob = probabilidade_poisson(2, -1, &erro);
  assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
  assert(prob == 0);
  printf("[passou] test_probabilidade_poisson_lambda_invalido\n");
}
// k < 0
void test_probabilidade_poisson_k_invalido(void){
  int erro = -1;
  double prob = probabilidade_poisson(-1, 2.0, &erro);
  assert(erro == ESTAT_ERRO_N_INVALIDO);
  assert(prob == 0);
  printf("[passou] test_probabilidade_poisson_k_invalido\n");
}

void test_densidade_uniforme(void) {
    int erro = -1;
    assert(quase_igual(densidade_uniforme(1.0, 0.0, 4.0, &erro), 0.25));
    assert(erro == ESTAT_OK);
    assert(densidade_uniforme(5.0, 0.0, 4.0, &erro) == 0.0);
    assert(erro == ESTAT_OK);
    densidade_uniforme(1.0, 4.0, 0.0, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    printf("[passou] test_densidade_uniforme\n");
}

void test_densidade_uniforme_a_invalido(void) { /*a >= b*/
  int erro = -1;
  double prob = densidade_uniforme(1, 5, 3, &erro);
  assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
  assert(prob == 0.0);
  printf("[passou] test_densidade_uniforme_a_invalido\n");
}

void test_densidade_uniforme_a_igual_b(void){
  int erro = ESTAT_OK;
  double prob = densidade_uniforme(2.0, 2.0, 2.0, &erro);
  assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
  assert(prob == 0.0);
  printf("[passou] test_densidade_uniforme_a_igual_b\n");
}

int main(void) {
    test_probabilidade_binomial_n_invalido();
    test_probabilidade_binomial_p_invalida();
    test_probabilidade_binomial_valida();
    test_probabilidade_binomial_k_menor_que_zero();
    test_probabilidade_binomial_k_maior_que_n();
    test_probabilidade_binomial_n_zero();
    test_probabilidade_geometrica_p_invalida();
    test_probabilidade_geometrica_k_invalido();
    test_probabilidade_geometrica();
    test_probabilidade_poisson_lambda_invalido();
    test_probabilidade_poisson_k_invalido();
    test_probabilidade_poisson();
    test_densidade_uniforme();
    test_densidade_uniforme_a_invalido();
    test_densidade_uniforme_a_igual_b();

    return 0;
}
