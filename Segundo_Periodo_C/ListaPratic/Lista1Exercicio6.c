#include <stdio.h>
#include <locale.h>

int main(){
    int quantidadePG, razao;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite a quantidade de elementos dessa PG: ");
    scanf("%d", &quantidadePG);

    printf("Digite a razao: ");
    scanf("%d", &razao);

    int pg[quantidadePG];
    for (int i = 0; i < quantidadePG; i++){
        if(i == 0){
            pg[i] = 1;
            printf("%d", pg[i]);
        }
        else{
            pg[i] = pg[i-1] * razao;
            printf(", %d", pg[i]);
        }
    }

    return 0;
}
