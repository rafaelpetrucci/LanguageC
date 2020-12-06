#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
    int numero;
    char sair[10];
    setlocale(LC_ALL, "Portuguese");
    do{
        printf("\nDigite um número: ");
        scanf("%d", &numero);
        if (numero < 0){
            printf("\n\nO valor digitado é negativo, digite um valor positivo.");
        }
        else{
            if (numero % 2 == 0){
                printf("\nO número %d é um número PAR", numero);
            }
            else{
                printf("\nO número %d é um número ÍMPAR", numero);
            }
        }
        printf("\n\nDeseja sair do programa? [S] ou [N]: ");
        scanf("%s", &sair);
        if (strcasecmp(sair, "S") == 0){
            printf("\n\nFim do programa!\n\n");
            break;
        }

    }while(1);

    return 0;
}
