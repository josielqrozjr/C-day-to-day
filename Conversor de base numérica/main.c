#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

  int valor;
  int opcao;

  // Solicitar e receber a entrada do dado solicitado
  printf("----- Conversor de Bases Numéricas -----\n\n");
  printf(">> 1: decimal para hexadecimal\n");
  printf(">> 2: hexadecimal para decimal\n\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);
  getchar(); // Limpar o buffer do teclado

  // Condição para cada opção de conversão
  switch (opcao) {
  case 1:
    printf("Digite o número: ");
    scanf("%d", &valor); // Receber o valor do usuário
    getchar();
    printf("\nDecimal: %d \nHexadecimal: %x\n", valor, valor);
    break;

  case 2:
    printf("Digite o número: ");
    scanf("%x", &valor); // Receber o valor do usuário
    getchar();
    printf("\nHexadecimal: %x \nDecimal: %d\n", valor, valor);
    break;

  default:
    printf("Opção inválida!");
    break;
  }

  return 0;
}