#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    int opcao;
    setlocale(LC_ALL, "Portuguese");
    do{
        printf("\n\nMenu"
               "\n[1] Numero 1"
               "\n[2] Numero 2"
               "\n[3] Numero 3"
               "\n[4] Numero 4"
               "\n[5] Numero 5"
               "\n[6] Numero 6"
               "\n[7] Numero 7"
               "\n[8] Numero 8"
               "\n[9] Numero 9"
               "\n[0] Sair"
               );
        printf("\nDigite a op��o: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("\n\nVoc� digitou a op��o 1!");
                break;
            case 2:
                printf("\n\nVoc� digitou a op��o 2!");
                break;
            case 3:
                printf("\n\nVoc� digitou a op��o 3!");
                break;
            case 4:
                printf("\n\nVoc� digitou a op��o 4!");
                break;
            case 5:
                printf("\n\nVoc� digitou a op��o 5!");
                break;
            case 6:
                printf("\n\nVoc� digitou a op��o 6!");
                break;
            case 7:
                printf("\n\nVoc� digitou a op��o 7!");
                break;
            case 8:
                printf("\n\nVoc� digitou a op��o 8!");
                break;
            case 9:
                printf("\n\nVoc� digitou a op��o 9!");
                break;
            case 0:
                printf("\n\nVoc� digitou a op��o 0! Tenha um bom dia! Fim do programa!");
                break;
            default:
                printf("\n\nVoc� digitou uma op��o inv�lida!");

        }
    }while(opcao != 0);





    return 0;
}
