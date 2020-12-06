#include <stdio.h>
#include <string.h>

int main() {

    unsigned int m, n, total, i, j;
    char resultado[30];

    while(1){
        scanf("%d %d", &m, &n);
        if (n == 0 && m == 0){
            break;
        }
        total = m + n;
        sprintf(resultado, "%d", total);
        for (i = 0; i < strlen(resultado);i++){
            if (resultado[i] == '0'){
                for(j = i; j < strlen(resultado); j++){
                    resultado[j] = resultado[j+1];
                }
                if (resultado[i] == '0'){
                    i--;
                }
            }
        }
        puts(resultado);
    }

    return 0;
}
