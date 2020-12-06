//Implemente a fun��o strcat de string.h utilizando qualquer estrutura de repeti��o.
//A fun��o strcat concatena o conte�do de uma string em outra. DICA: Cuidado com o espa�o em mem�ria.

#include <stdio.h>

int main(){

    int i;
    int count = 0;
    char texto1[50];
    char texto2[50];

    printf("Digite um texto: ");
    scanf("%s", texto1);

    printf("Digite dois texto: ");
    scanf("%s", texto2);

    for (i = 0; texto2[count] != '\0'; i++){
        if (texto1[i] == '\0'){
            texto1[i] = texto2[count];
            texto1[i+1] = '\0';
            count++;
        }

    }
    puts(texto1);
    return 0;
}
