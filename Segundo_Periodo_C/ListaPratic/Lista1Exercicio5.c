#include <stdio.h>
#include <locale.h>

int main(){
    int quantidadePA, razao;
    setlocale(LC_ALL, "Portuguese");
    printf("\nDigite a quantidade de elementos dessa PA: ");
    scanf("%d", &quantidadePA);

    printf("\nDigite a razão da PA: ");
    scanf("%d", &razao);

    int pa[quantidadePA];
    for (int i = 0; i < quantidadePA; i++){
        if(i == 0){
            pa[i] = 0;
            printf("%d", pa[i]);
        }
        else{
            pa[i] = pa[i-1] + razao;
            printf(", %d", pa[i]);
        }
    }

    return 0;
}

