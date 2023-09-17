#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    float preco;
    char descricao[50];
} Produto;

typedef struct {
    int codigo;
    char nome[50];
} Vendedor;

typedef struct {
  int codigoVendedor;
  int codigoProduto;
  int qtdVendida;
} Vendas;

void lerProdutos(char arquivo[], Produto produtos[], int *quantProdutos) {
    FILE *arqProduto = fopen(arquivo, "r");
    if (arqProduto == NULL) { perror("ERRO no arquivo produtos!"); exit(1); }

    fscanf(arqProduto, "%d", quantProdutos);
    for (int i = 0; i < *quantProdutos; i++) {
        fscanf(arqProduto, "%d %f %s", &produtos[i].codigo, &produtos[i].preco, produtos[i].descricao);
    }

    fclose(arqProduto);
}

void lerVendedores(char arquivo[], Vendedor vendedores[], int *quantVendedores) {
    FILE *arqVendedores = fopen(arquivo, "r");
    if (arqVendedores == NULL) { perror("ERRO no arquivo vendedores!"); exit(1); }

    fscanf(arqVendedores, "%d", quantVendedores);
    for (int i = 0; i < *quantVendedores; i++) {
        fscanf(arqVendedores, "%d %s", &vendedores[i].codigo, vendedores[i].nome);
    }

    fclose(arqVendedores);
}

void lerVendas(char arquivo[], Vendas vendas[], int *quantVendas) {
    FILE* arqVendas = fopen(arquivo, "r");
    if (arqVendas == NULL) { perror("ERRO no arquivo vendas!"); exit(1); }

    fscanf(arqVendas, "%d", quantVendas);
    for (int i = 0; i < *quantVendas; i++) {
        fscanf(arqVendas, "%d %d %d", &vendas[i].codigoVendedor, &vendas[i].codigoProduto, &vendas[i].qtdVendida);
    }

    fclose(arqVendas);
}

int main(int argc, const char * argv[]) {

  int qtdProdutos, qtdVendedores, qtdVendas;
  Produto produtos[100];
  Vendedor vendedores[100];
  Vendas vendas[100];
  float totalPorProduto[100] = {0};
  float totalPorVendedor[100] = {0};
  float totalGeral;

  lerProdutos("produtos.txt", produtos, &qtdProdutos);
  lerVendedores("vendedores.txt", vendedores, &qtdVendedores);
  lerVendas("vendas.txt", vendas, &qtdVendas);

  // Totais de vendas por produto e geral
  for (int v = 0; v < qtdVendas; v++) {
    for (int p = 0; p < qtdProdutos; p++) {
      if (vendas[v].codigoProduto == produtos[p].codigo){
        totalPorProduto[p] += vendas[v].qtdVendida * produtos[p].preco;
        totalGeral += vendas[v].qtdVendida * produtos[p].preco;
      }
    }
  }
  
  // Totais de vendas por vendedor
  for (int v = 0; v < qtdVendas; v++) {
    for (int p = 0; p < qtdVendedores; p++) {
      for (int j = 0; j < qtdProdutos; j++) {
        if (vendas[v].codigoVendedor == vendedores[p].codigo){
          if (vendas[v].codigoProduto == produtos[j].codigo){
            totalPorVendedor[p] += vendas[v].qtdVendida * produtos[j].preco;
          }
        }
      }
    }
  }

  FILE* arqTotais = fopen("totais.txt", "w");
  if (arqTotais == NULL) { perror("ERROR ao registrar totais!"); exit(1); }
  
  fprintf(arqTotais, "Log de Vendas:\n\n");
  for (int linha = 0; linha < qtdVendas; linha++) {
    fprintf(arqTotais, "%d %d %d\n", 
      vendas[linha].codigoVendedor, 
      vendas[linha].codigoProduto, 
      vendas[linha].qtdVendida);
  }

  fprintf(arqTotais, "\nCatalogo de Produtos:\n\n");
  for (int linha = 0; linha < qtdProdutos; linha++) {
    fprintf(arqTotais, "%d %.2f %s\n", 
      produtos[linha].codigo, 
      produtos[linha].preco, 
      produtos[linha].descricao);
  }

  fprintf(arqTotais, "\nLista de Vendedores:\n\n");
  for (int linha = 0; linha < qtdVendedores; linha++) {
    fprintf(arqTotais, "%d %s\n", 
      vendedores[linha].codigo,
      vendedores[linha].nome);
  }

  fprintf(arqTotais, "\nTotal geral vendido: R$%.2f\n", totalGeral);

  fprintf(arqTotais, "\nTotal de vendas de cada produto:\n");
  for (int linha = 0; linha < qtdProdutos; linha++) {
    fprintf(arqTotais, "Produto %d (%s): R$%.2f\n", 
      produtos[linha].codigo, 
      produtos[linha].descricao,
      totalPorProduto[linha]);
  }

  fprintf(arqTotais, "\nTotal de vendas de cada vendedor:");
  for (int linha = 0; linha < qtdVendedores; linha++) {
    fprintf(arqTotais, "\nVendedor %d (%s): R$%.2f", 
      vendedores[linha].codigo, 
      vendedores[linha].nome, 
      totalPorVendedor[linha]);
  }

  fclose(arqTotais);
  
  return 0;
}