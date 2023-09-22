#include <stdio.h>

// Created by Queiroz, JR.

// -------------------------------------------
// LEI DE FORMAÇÃO DAS FUNÇÕES f(x) e g(x)
// -------------------------------------------
double formacao_funcao_f(double x) {
  return (x * x) + 1;
}

double formacao_funcao_g(double x) {
  return (2 * x) - 3;
}

// -------------------------------------------
// CÁLCULO DA FUNÇÃO COMPOSTA (g ° f)
// -------------------------------------------
double funcao_g_f(double (*f)(double), double (*g)(double), double x) {
  return g(f(x));
}

// -------------------------------------------
// CÁLCULO DA FUNÇÃO COMPOSTA (g ° g)
// -------------------------------------------
double funcao_g_g(double (*g)(double), double x) {
  return g(g(x));
}

// -------------------------------------------
// CÁLCULO DA FUNÇÃO COMPOSTA (f ° f)
// -------------------------------------------
double funcao_f_f(double (*f)(double), double x) {
  return f(f(x));
}

// -------------------------------------------
// CÁLCULO DA FUNÇÃO COMPOSTA (f ° g)
// -------------------------------------------
double funcao_f_g(double (*f)(double), double (*g)(double), double x) {
  return f(g(x));
}

int main(int argc, const char * argv[]) {
  
  double valor_x;

  // Solicitar o valor de x para o usuário
  printf("Digite o valor para x: ");
  scanf("%lf", &valor_x);
  getchar(); // Limpar o buffer do teclado

  // Armazena o cálculo das funções f(x) e g(x) desejadas
  double (*funcao_f)(double) = formacao_funcao_f;
  double (*funcao_g)(double) = formacao_funcao_g;

  // Realizar o cálculo as composições
  double resultadoG_F = funcao_g_f(funcao_f, funcao_g, valor_x);
  double resultadoG_G = funcao_g_g(funcao_g, valor_x);
  double resultadoF_F = funcao_f_f(funcao_f, valor_x);
  double resultadoF_G = funcao_f_g(funcao_f, funcao_g, valor_x);

  // Imprimir os resultados no console
  printf("(g ° f)(%.2lf) = %.2lf\n", valor_x, resultadoG_F);
  printf("(g ° g)(%.2lf) = %.2lf\n", valor_x, resultadoG_G);
  printf("(f ° f)(%.2lf) = %.2lf\n", valor_x, resultadoF_F);
  printf("(f ° g)(%.2lf) = %.2lf\n", valor_x, resultadoF_G);

  return 0;
}
