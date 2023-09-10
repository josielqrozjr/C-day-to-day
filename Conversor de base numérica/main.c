#include <stdio.h>

int main() {

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
  if (opcao == 1) {
    printf("Digite o número: ");
    scanf("%d", &valor); // Receber o valor do usuário
    getchar();
    printf("\nDecimal: %d \nHexadecimal: %x", valor, valor);
  } else if (opcao == 2) {
    printf("Digite o número: ");
    scanf("%x", &valor); // Receber o valor do usuário
    getchar();
    printf("\nHexadecimal: %x \nDecimal: %d", valor, valor);
  } else {
    printf("Opção inválida!");
  }
  
  return 0;
}