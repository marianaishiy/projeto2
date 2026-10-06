#include "distribuicoes.h"
#include <math.h>

// Calcula C(n, k) iterativamente a fim de evitar overflow
static double binomio(double n, double k){
  if (k > n - k) k = n - k;
  double c = 1.0;
  for (int i = 1; i <= k; i++) {
    c = c * (n - k + i ) / i;
}
return c;
}

// Calcula P(X = k) , X ~ b(n, p)
 double probabilidade_binomial(int k, int n, double p, int *erro){
  if (n <= 0 || k < 0){
    *erro = ESTAT_ERRO_N_INVALIDO;
    return 0.0;
  }
  if (p < 0.0 || p > 1.0) {
    *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
    return 0.0;
  }

  *erro = ESTAT_OK;
  if(k > n) return 0.0;
  return binomio(n, k) * pow(p, k) * pow (1.00-p, n - k);
}

// Calcula P(X = k), X ~ G(p) 
 double probabilidade_geometrica(int k, double p, int *erro){
   if( k < 0){
     *erro = ESTAT_ERRO_N_INVALIDO;
     return 0.0;
   }
   if(p <= 0.0 || p > 1.0){ 
    *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
    return 0.0; 
  }
  *erro = ESTAT_OK;
  return p * pow((1.0-p), k);
}

// Calcula P(X = k), X ~ Po(lambda)
 double probabilidade_poisson(int k, double lambda, int *erro){
  if(k < 0){
    *erro = ESTAT_ERRO_N_INVALIDO;
    return 0.0;
  }
  if(lambda <= 0){
    *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
    return 0.0;
  }
  *erro = ESTAT_OK;
  // exp(-lambda + k * ln(lambda) - ln(k!)) evita overflow do fatorial
  return exp(-lambda + k * log(lambda) - lgamma(k + 1.0));
}
// Calcula f(x), se X tem distribuição uniforme contínua no intervalo [a, b]
 double densidade_uniforme(double x, double a, double b, int *erro){
  if(a >= b){  
    *erro = ESTAT_ERRO_PARAMETRO_INVALIDO;
    return 0.0;
  }
  *erro = ESTAT_OK;
    if(x < a || x > b) return 0.0;
    return 1.0/(b-a);
}
