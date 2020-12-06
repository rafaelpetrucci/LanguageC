//Implemente a função strcmp de string.h utilizando qualquer estrutura de repetição.
//A função strcmp compara os conteúdos de duas strings e verifica se são iguais retornando 0.


#include <stdio.h>

int main(){

    char array1[50];
    char array2[50];

    printf("Digite um texto: ");
    scanf("%s", array1);

    printf("Digite dois texto: ");
    scanf("%s", array2);

    for (int i = 0; i < 50; i++){
        if (array1[i] == '\0'){
            if (array2[i] == '\0'){
                break;
            }
            printf("Sao diferentes.");
            return 0;
        }
        if(array1[i] != array2[i]){
            printf("Sao diferentes.");
            return 0;
        }
    }
    printf("Sao iguais!");
    return 0;
}
