#include <stdio.h>
#include <locale.h>

int main(){
    int numero, soma;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um número: ");
    scanf("%d", &numero);
    soma = numero;
    printf("%d! = %d ",numero, soma);
    for(int i = numero - 1; i > 0; i--){
        soma = soma * i;
        printf("* %d ", i);
    }
    printf("= %d", soma);

    return 0;
}
