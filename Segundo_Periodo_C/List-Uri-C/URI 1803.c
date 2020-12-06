#include <stdio.h>
#include <string.h>

int transformaInteiro(char *um, char *dois, char *tres, char *quatro, int indice){
    int i = indice;
    int num;
    char junto[5];

    junto[0] = um[i];
    junto[1] = dois[i];
    junto[2] = tres[i];
    junto[3] = quatro[i];
    junto[4] = '\0';
    num = atoi(junto);
    return num;
}


int main() {

    int i, letra, inicio, fim, resultado;
    char pLinha[82], sLinha[82], tLinha[82], qLinha[82];
    scanf("%s", pLinha);
    scanf("%s", sLinha);
    scanf("%s", tLinha);
    scanf("%s", qLinha);
    inicio = transformaInteiro(pLinha, sLinha, tLinha, qLinha, 0);
    fim = transformaInteiro(pLinha, sLinha, tLinha, qLinha, (strlen(pLinha) - 1));

    for (i = 1; i < strlen(pLinha) - 1; i++){
        letra = transformaInteiro(pLinha, sLinha, tLinha, qLinha, i);
        resultado = ((inicio * letra) + fim) % 257;
        printf("%c", resultado);
    }

    printf('\0');
    printf("\n");

    return 0;
}
