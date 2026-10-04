#include "variancia_modelos.h"
#include <stdio.h>
#include "erros.h"
#include "esperanca.h"
#include "distribuicoes.h"

const char *mensagem_erro(int codigo_erro){
    switch(codigo_erro){
        case ESTAT_OK:
            return "Sem erros";
        case ESTAT_ERRO_PARAMETRO_INVALIDO:
            return "Parametro invalido";
        case ESTAT_ERRO_N_INVALIDO:
            return "N invalido";
        case ESTAT_ERRO_DIVISAO_ZERO:
            return "Divisao por zero";
        case ESTAT_ERRO_TAMANHOS_DIFERENTES:
            return "Tamanhos diferentes";
        default:
            return "Código de erro desconhecido";
    }
}
void imprime_res(const char *rotulo, double valor, int codigo_erro){
    if(codigo_erro==ESTAT_OK){
        printf("%s: %.6f\n", rotulo, valor);
    }
    else{
        printf("%s: %s\n", rotulo, mensagem_erro(codigo_erro));
    }
}
void demo_esperanca(){
    int erro;
    double v;
    printf("=====Esperança dos modelos=====\n");
    v= esperanca_binomial(10,0.5,&erro);
    imprime_res("Esperança Binomial(10,0.5)",v,erro);
    v=esperanca_geometrica(0.5,&erro);
    imprime_res("Esperança Geometrica(0.5)",v,erro);
    v=esperanca_poisson(10,&erro);
    imprime_res("Esperança de Poisson",v,erro);
    v=esperanca_uniforme(5,10,&erro);
    imprime_res("Esperança Uniforme(5,10)",v,erro);
    v = esperanca_binomial(0, 0.5, &erro);
imprime_res("Esperança Binomial(0, 0.5) [invalido]", v, erro); 
v = esperanca_uniforme(10, 5, &erro);
imprime_res("Esperança Uniforme(10, 5) [invalido]", v, erro);
}
void demo_variancia(){
    int erro;
    double v;
    printf("=====Variância dos modelos=====\n");
    v=variancia_binomial(10,0.5,&erro);
    imprime_res("Variancia Binomial(10, 0.5)", v, erro);   
    v = variancia_geometrica(0.5, &erro);
    imprime_res("Variancia Geometrica(0.5)", v, erro);         
    v = variancia_uniforme(0, 10, &erro);
    imprime_res("Variancia Uniforme(0, 10)", v, erro);          
    v = variancia_poisson(4, &erro);
    imprime_res("Variancia Poisson(4)", v, erro);              
    v = variancia_binomial(10, 1.5, &erro);
    imprime_res("Variancia Binomial(10, 1.5) [invalido]", v, erro);

}
void demo_distribuicoes(){
    double v;
    int erro;
    printf("=====Distribuições=====\n");
    v = probabilidade_binomial(5, 10, 0.5, &erro);
    imprime_res("P Binomial(k=5, n=10, p=0.5)", v, erro);      
    v = probabilidade_geometrica(3, 0.5, &erro);
    imprime_res("P Geometrica(k=3, p=0.5)", v, erro);          
    v = probabilidade_poisson(2, 4, &erro);
    imprime_res("P Poisson(k=2, lambda=4)", v, erro);       
    v = densidade_uniforme(5, 0, 10, &erro);
    imprime_res("Densidade Uniforme(x=5, a=0, b=10)", v, erro);
    v = probabilidade_binomial(5, 10, 1.5, &erro);
    imprime_res("P Binomial(k=5, n=10, p=1.5) [invalido]", v, erro);    
    v = probabilidade_poisson(2, -1, &erro);
    imprime_res("P Poisson(k=2, lambda=-1) [invalido]", v, erro);   
}
int main(){
    demo_esperanca();
    demo_variancia();
    demo_distribuicoes();

    return 0;
}

