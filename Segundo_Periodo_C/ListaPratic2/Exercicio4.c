//Implemente a função strlen de string.h utilizando qualquer estrutura de repetição.
//A função strlen retorna a quantidade de caracteres em uma string. DICA: A string termina com o caractere especial '\0'.

#include <stdio.h>

int main(){
    int i;
    char texto1[50];

    printf("Digite um texto: ");
    scanf("%s", texto1);


    for (i = 0; texto1[i] != '\0'; i++){}

    printf("%d", i);
    return 0;
}
