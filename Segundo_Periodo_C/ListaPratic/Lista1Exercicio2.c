#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
    int numero;
    char sair[10];
    setlocale(LC_ALL, "Portuguese");
    do{
        printf("\nDigite um n�mero: ");
        scanf("%d", &numero);
        if (numero < 0){
            printf("\n\nO valor digitado � negativo, digite um valor positivo.");
        }
        else{
            if (numero % 2 == 0){
                printf("\nO n�mero %d � um n�mero PAR", numero);
            }
            else{
                printf("\nO n�mero %d � um n�mero �MPAR", numero);
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
