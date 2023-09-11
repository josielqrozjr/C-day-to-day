/*
 Sistema de Banco de dados simples
 Objetivo: seleciona vendedores por região
 
 Created by Josiel Queiroz Jr on 10/09/23.
*/

#include <stdio.h>
#include <stdlib.h>
#include <_ctype.h>

int main(int argc, const char * argv[]) {
    
    char regiao, vendedor;
    
    printf("Regiões: Sul, Norte\n");
    printf("Informe a primeira letra da região: ");
    regiao = getchar();
    regiao = toupper(regiao);
    putchar('\n');
    
    switch (regiao) {
            
        case 'S': // Região Sul
            printf("Vendedores: Amanda, Ricardo, Gabriel \n");
            printf("Informe a primeira letra do vendedor: ");
            vendedor = getchar();
            vendedor = toupper(vendedor);
            switch (vendedor) {
                case 'R':
                    printf("Total de vendas: R$ 10,2%d", 5000);
                    break;
                case 'A':
                    printf("Total de vendas: R$ 10,2%d", 1127);
                    break;
                case 'G':
                    printf("Total de vendas: R$ 10,2%d", 22000);
                    break;
            }
            break;
        case 'N': // Região Norte
            printf("Vendedores: Josiel, Vitória, Ana \n");
            printf("Informe a primeira letra do vendedor: ");
            vendedor = toupper(getchar());
            switch (vendedor) {
                case 'J':
                    printf("Total de vendas: R$ 10,2%d", 960);
                    break;
                case 'v':
                    printf("Total de vendas: R$ 10,2%d", 35000);
                    break;
                case 'A':
                    printf("Total de vendas: R$ 10,2%d", 2201);
                    break;
            }
            break;
            
        default:
            printf("Comando inválido!");
        break;}
    
    
    return 0;
}
