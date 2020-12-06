#include <stdio.h>
#include <string.h>

int main() {
    int casos, inicio, fim, i, j, aux;
    char caracter[10], troca;
    scanf("%d", &casos);
    for (i = 0; i < casos; i++){
        scanf("%d %d", &inicio, &fim);
        for (j = inicio; j <= fim; j++){
            printf("%d", j);
        }
        for (j = fim; j >= inicio; j--){
            sprintf(caracter, "%d", j);
            if (strlen(caracter) > 1){
                for(aux = strlen(caracter)-1; aux >= 0; aux--){
                    printf("%c", caracter[aux]);
                }
            }
            else{
                printf("%c", caracter[0]);
            }
        }
        printf("\n");
    }

    return 0;
}
