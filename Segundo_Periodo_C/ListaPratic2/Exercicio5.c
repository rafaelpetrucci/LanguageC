//Palíndromo é a frase ou palavra que se pode ler, indiferentemente,
//da esquerda para a direita ou vice-versa, como por exemplo a palavra ARARA ou o nome ANA.
//Escreva um programa que receba do usuário um texto e informe se é palíndromo ou não.
//Desconsidere caracteres em maíusculo, por exemplo, o nome Ana deve ser identificado como palíndromo.

#include <stdio.h>

int count(char *texto){ //contador de string(texto);
    int i;
    for (i = 0; texto[i] != '\0'; i++);
    return i;
}

int main(){
    int i;
    char texto[50];

    printf("Digite um texto: ");
    gets(texto);

    i = count(texto);
    for(int x = 0; x < i; x++){ //tira os espaços da string;
        if(texto[x] == '\0'){
            break;
        }
        if(texto[x] == ' ') {
            for(int y = x; y <= i; y++){
                texto[y] = texto[y+1];
            }
        }
    }
    i = count(texto) - 1;
    for(int j = 0;j < i; j++){ // verifica se é um palíndromo
        if(toupper(texto[j]) != toupper(texto[i])){
            printf("Nao eh um palindromo!");
            return 0;
        }
        i--;
    }
    printf("Eh um palindromo!");
    return 0;
}
