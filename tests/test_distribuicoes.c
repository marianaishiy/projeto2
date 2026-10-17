#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "distribuicoes.h"

int aproximadamente(double x, double y) {
    return fabs(y - x) < 0.000001;
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
    assert(aproximadamente(prob, 0.375));
    printf("[passou] test_probabilidade_binomial_valida\n");
}

void test_probabilidade_geometrica(void) {
    int erro = -1;
    double prob = probabilidade_geometrica(2, 0.5, &erro); /* 0.5 * 0.25 */
    assert(erro == ESTAT_OK);
    assert(aproximadamente(prob, 0.125));
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
    assert(aproximadamente(prob, exp(-2.0)));
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
    assert(aproximadamente(densidade_uniforme(1.0, 0.0, 4.0, &erro), 0.25));
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

/* ---- testes adicionais ---- */

/* exercita o laco de binomio(): C(10,3)=120, C(10,5)=252 e o caso k > n-k */
void test_probabilidade_binomial_coeficiente(void) {
    int erro = -1;
    /* C(10,3) * 0.5^10 = 120/1024 */
    assert(aproximadamente(probabilidade_binomial(3, 10, 0.5, &erro), 0.1171875));
    assert(erro == ESTAT_OK);
    /* C(10,5) * 0.5^10 = 252/1024 */
    assert(aproximadamente(probabilidade_binomial(5, 10, 0.5, &erro), 0.24609375));
    assert(erro == ESTAT_OK);
    /* k=7 > n-k=3: usa a simetria C(10,7) = C(10,3) */
    assert(aproximadamente(probabilidade_binomial(7, 10, 0.5, &erro), 0.1171875));
    assert(erro == ESTAT_OK);
    printf("[passou] test_probabilidade_binomial_coeficiente\n");
}

void test_probabilidade_binomial_p_maior_que_um(void) {
    int erro = ESTAT_OK;
    double prob = probabilidade_binomial(1, 3, 1.5, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_binomial_p_maior_que_um\n");
}

/* p = 0 e p = 1 sao validos na binomial */
void test_probabilidade_binomial_p_limites(void) {
    int erro = -1;
    assert(aproximadamente(probabilidade_binomial(0, 4, 0.0, &erro), 1.0));
    assert(erro == ESTAT_OK);
    assert(aproximadamente(probabilidade_binomial(2, 4, 0.0, &erro), 0.0));
    assert(erro == ESTAT_OK);
    assert(aproximadamente(probabilidade_binomial(4, 4, 1.0, &erro), 1.0));
    assert(erro == ESTAT_OK);
    assert(aproximadamente(probabilidade_binomial(0, 4, 1.0, &erro), 0.0));
    assert(erro == ESTAT_OK);
    printf("[passou] test_probabilidade_binomial_p_limites\n");
}

/* n grande: 200! estouraria um double, mas o binomio iterativo funciona */
void test_probabilidade_binomial_n_grande(void) {
    int erro = -1;
    double prob = probabilidade_binomial(100, 200, 0.5, &erro);
    assert(erro == ESTAT_OK);
    assert(aproximadamente(prob, 0.05634847900925642));
    printf("[passou] test_probabilidade_binomial_n_grande\n");
}

void test_probabilidade_geometrica_p_maior_que_um(void) {
    int erro = -1;
    double prob = probabilidade_geometrica(2, 1.5, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_geometrica_p_maior_que_um\n");
}

/* p = 1: o sucesso ocorre sempre na primeira tentativa */
void test_probabilidade_geometrica_p_um(void) {
    int erro = -1;
    assert(aproximadamente(probabilidade_geometrica(0, 1.0, &erro), 1.0));
    assert(erro == ESTAT_OK);
    assert(aproximadamente(probabilidade_geometrica(2, 1.0, &erro), 0.0));
    assert(erro == ESTAT_OK);
    printf("[passou] test_probabilidade_geometrica_p_um\n");
}

/* k > 0 exercita o lgamma: e^-3 * 3^2 / 2! */
void test_probabilidade_poisson_k_positivo(void) {
    int erro = -1;
    double prob = probabilidade_poisson(2, 3.0, &erro);
    assert(erro == ESTAT_OK);
    assert(aproximadamente(prob, 0.22404180765538775));
    printf("[passou] test_probabilidade_poisson_k_positivo\n");
}

void test_probabilidade_poisson_lambda_zero(void) {
    int erro = -1;
    double prob = probabilidade_poisson(2, 0.0, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    assert(prob == 0.0);
    printf("[passou] test_probabilidade_poisson_lambda_zero\n");
}

/* k grande: com k = 200, tanto 200! quanto 200^200 estouram um double,
   mas a escala logaritmica (lgamma) calcula o valor sem problemas */
void test_probabilidade_poisson_k_grande(void) {
    int erro = -1;
    double prob = probabilidade_poisson(200, 200.0, &erro);
    assert(erro == ESTAT_OK);
    assert(aproximadamente(prob, 0.028197727685920822));
    printf("[passou] test_probabilidade_poisson_k_grande\n");
}

/* x = a e x = b pertencem ao intervalo [a, b] */
void test_densidade_uniforme_extremos(void) {
    int erro = -1;
    assert(aproximadamente(densidade_uniforme(0.0, 0.0, 4.0, &erro), 0.25));
    assert(erro == ESTAT_OK);
    assert(aproximadamente(densidade_uniforme(4.0, 0.0, 4.0, &erro), 0.25));
    assert(erro == ESTAT_OK);
    printf("[passou] test_densidade_uniforme_extremos\n");
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

    test_probabilidade_binomial_coeficiente();
    test_probabilidade_binomial_p_maior_que_um();
    test_probabilidade_binomial_p_limites();
    test_probabilidade_binomial_n_grande();
    test_probabilidade_geometrica_p_maior_que_um();
    test_probabilidade_geometrica_p_um();
    test_probabilidade_poisson_k_positivo();
    test_probabilidade_poisson_lambda_zero();
    test_probabilidade_poisson_k_grande();
    test_densidade_uniforme_extremos();

    return 0;
}
