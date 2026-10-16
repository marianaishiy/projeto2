
#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

#include "correlacao.h"
#include "erros.h"

// compara resultados com uma pequena tolerancia numerica
static void verificar_resultado(double obtido, double esperado) {
    assert(fabs(obtido - esperado) < 1e-9);
}

// testes da funcao covariancia.
static void testar_covariancia(void) {
    double x[] = {1, 2, 3};
    double y_positivo[] = {3, 5, 7};
    double y_negativo[] = {7, 5, 3};

    int erro = -1;
    double resultado;

    // covariancia positiva
    resultado = covariancia(x, y_positivo, 3, &erro);
    verificar_resultado(resultado, 2.0);
    assert(erro == ESTAT_OK);

    // covariancia negativa
    resultado = covariancia(x, y_negativo, 3, &erro);
    verificar_resultado(resultado, -2.0);
    assert(erro == ESTAT_OK);

    // tamanho de amostra invalido
    resultado = covariancia(x, y_positivo, 1, &erro);
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_N_INVALIDO);

    // ponteiro de amostra invalido
    resultado = covariancia(NULL, y_positivo, 3, &erro);
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);

    printf("testes de covariancia: OK\n");
}

// teste da funcao correlacao
static void testar_correlacao(void) {
    double x[] = {1, 2, 3};
    double y_positivo[] = {3, 5, 7};
    double y_negativo[] = {7, 5, 3};
    double constante[] = {4, 4, 4};

    int erro = -1;
    double resultado;

    // correlacao positiva perfeita
    resultado = correlacao(x, y_positivo, 3, &erro);
    verificar_resultado(resultado, 1.0);
    assert(erro == ESTAT_OK);

    // correlacao negativa perfeita
    resultado = correlacao(x, y_negativo, 3, &erro);
    verificar_resultado(resultado, -1.0);
    assert(erro == ESTAT_OK);

    // variancia zero em X
    resultado = correlacao(constante, y_positivo, 3, &erro);
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_DIVISAO_ZERO);

    // variancia zero em Y
    resultado = correlacao(x, constante, 3, &erro);
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_DIVISAO_ZERO);

    // tamanho invalido
    resultado = correlacao(x, y_positivo, 0, &erro);
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_N_INVALIDO);

    // amostra invalida
    resultado = correlacao(x, NULL, 3, &erro);
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);

    printf("testes de correlacao: OK\n");
}

// teste da funcao de regressao linear
static void testar_regressao(void) {
    double x[] = {1, 2, 3};
    double y_positivo[] = {3, 5, 7};
    double y_negativo[] = {7, 5, 3};
    double constante[] = {4, 4, 4};

    int erro = -1;
    double resultado;

    // coeficiente angular positivo
    resultado = coeficiente_linear_regressao(
        x, y_positivo, 3, &erro
    );
    verificar_resultado(resultado, 2.0);
    assert(erro == ESTAT_OK);

    // coeficiente angular negativo
    resultado = coeficiente_linear_regressao(
        x, y_negativo, 3, &erro
    );
    verificar_resultado(resultado, -2.0);
    assert(erro == ESTAT_OK);

    // coeficiente angular zero e resultado valido
    resultado = coeficiente_linear_regressao(
        x, constante, 3, &erro
    );
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_OK);

    // variancia zero em X
    resultado = coeficiente_linear_regressao(
        constante, y_positivo, 3, &erro
    );
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_DIVISAO_ZERO);

    // tamanho invalido
    resultado = coeficiente_linear_regressao(
        x, y_positivo, 1, &erro
    );
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_N_INVALIDO);

    // ponteiro invalido
    resultado = coeficiente_linear_regressao(
        NULL, y_positivo, 3, &erro
    );
    verificar_resultado(resultado, 0.0);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);

    printf("testes de regressao: OK\n");
}

int main(void) {
    testar_covariancia();
    testar_correlacao();
    testar_regressao();

    printf("todos os testes do modulo passaram!\n");
    return 0;
}
