#include <stdio.h>
#include <locale.h>

int main(){
    int ano;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um ano: ");
    scanf("%d", &ano);

    if (ano % 4 == 0){
        printf("O ano de %d, É um ano bissexto!", ano);
    }
    else{
        printf("O ano de %d, NÃO É um ano bissexto!", ano);
    }

    return 0;
}
