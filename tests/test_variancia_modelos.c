#include "variancia_modelos.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

//função que permite a checagem de aproximação com double 
int aproximadamente(double x, double y){
    return fabs(y-x)<0.000001;
}
//testes de variancia binomial
void teste_variancia_binomial_erro_n_invalido(){
    int erro;
    variancia_binomial(-2, 0.5, &erro);
    assert(erro == ESTAT_ERRO_N_INVALIDO);
    printf("passou no teste_variancia_binomial_erro_n_invalido\n");
}

void teste_variancia_binomial_erro_p_invalido(){
    int erro;
    variancia_binomial(10, -1, &erro);
    assert(erro == ESTAT_ERRO_PARAMETRO_INVALIDO);
    printf("passou no teste_variancia_binomial_erro_p_invalido\n");
}
void teste_variancia_binomial_normal(){
    int erro;
    double res = variancia_binomial(10, 0.5, &erro);
    assert(erro == ESTAT_OK);                      
    assert(aproximadamente(res, 2.5));       
    printf("passou no teste_variancia_binomial_normal\n");}

void teste_variancia_binomial_p_igual_1(){
    int erro;
    double res = variancia_binomial(10, 1, &erro);
    assert(erro == ESTAT_OK);
    assert(aproximadamente(res, 0));
    printf("passou no teste_variancia_binomial_p_igual_1\n");
}
void teste_variancia_binomial_n_igual_0(){
    int erro;
    variancia_binomial(0, 0.5, &erro);
    assert(erro == ESTAT_ERRO_N_INVALIDO);
    printf("passou no teste_variancia_binomial_n_igual_0\n");
}
void teste_variancia_binomial_p_igual_0(){
    int erro;
    double res = variancia_binomial(10, 0, &erro);
    assert(erro == ESTAT_OK);
    assert(aproximadamente(res, 0));
    printf("passou no teste_variancia_binomial_p_igual_0\n");
}

//teste de variancia geométrica
void teste_variancia_geo_erro_div_por_zero(){
    int erro;
    variancia_geometrica(0,&erro);
    assert(erro==ESTAT_ERRO_DIVISAO_ZERO);
    printf("passou no teste_variancia_geo_erro_div_por_zero\n");

}

void teste_variancia_geo_erro_p_invalido(){
    int erro;
    variancia_geometrica(2,&erro);
    assert(erro==ESTAT_ERRO_PARAMETRO_INVALIDO);
    printf("passou no teste_variancia_geo_erro_p_invalido\n");
}
void teste_variancia_geo_normal(){
    int erro;
    double res=variancia_geometrica(0.5,&erro);
    assert(erro==ESTAT_OK);
    assert(aproximadamente(res,2));
    printf("passou no teste_variancia_geo_normal\n");
}
void teste_variancia_geo_p_igual_1(){
    int erro;
    double res=variancia_geometrica(1,&erro);
    assert(erro==ESTAT_OK);
    assert(aproximadamente(res,0));
    printf("passou no teste_variancia_geo_p_igual_1\n");
}

//testes para variancia de poisson
void teste_variancia_poisson_lambda_invalido(){
    int erro;
    variancia_poisson(0,&erro);
    assert(erro==ESTAT_ERRO_PARAMETRO_INVALIDO);
    printf("passou no teste_variancia_poisson_lambda_invalido\n");
}
void teste_variancia_poisson_normal(){
    int erro;
    double res=variancia_poisson(10,&erro);
    assert(erro==ESTAT_OK);
    assert(aproximadamente(res,10));
    printf("passou no teste_variancia_poisson_normal\n");
}
//testes para variancia uniforme
void teste_variancia_uniforme_erro_a_maior_ou_igual_b(){
    int erro;
    variancia_uniforme(5,5,&erro);
    assert(erro==ESTAT_ERRO_PARAMETRO_INVALIDO);
    printf("passou no teste_variancia_uniforme_erro_a_maior_ou_igual_b\n");
}
void teste_variancia_uniforme_normal(){
    int erro;
    double res=variancia_uniforme(0,10,&erro);
    assert(erro==ESTAT_OK);
    assert(aproximadamente(res,8.333333));      
    printf("passou no teste_variancia_uniforme_normal\n");
}
void teste_variancia_uniforme_a_negativo(){
    int erro;
    double res=variancia_uniforme(-5,5,&erro);
    assert(erro==ESTAT_OK);
    assert(aproximadamente(res,8.333333));      
    printf("passou no teste_variancia_uniforme_a_negativo\n");
}

int main(){
    //testes de variancia binomiais
    teste_variancia_binomial_erro_n_invalido();
    teste_variancia_binomial_erro_p_invalido();
    teste_variancia_binomial_normal();
    teste_variancia_binomial_p_igual_1();
    teste_variancia_binomial_n_igual_0();
    teste_variancia_binomial_p_igual_0();
    //testes de variancia geometrica
    teste_variancia_geo_erro_div_por_zero();
    teste_variancia_geo_erro_p_invalido();
    teste_variancia_geo_normal();
    teste_variancia_geo_p_igual_1();
    //testes de variancia poisson
    teste_variancia_poisson_lambda_invalido();
    teste_variancia_poisson_normal();
    //testes de variancia uniforme
    teste_variancia_uniforme_erro_a_maior_ou_igual_b();
    teste_variancia_uniforme_normal();
    teste_variancia_uniforme_a_negativo();
    return 0;
}