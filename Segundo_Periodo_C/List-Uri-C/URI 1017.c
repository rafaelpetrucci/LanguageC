#include <stdio.h>

int main() {

    float horas, velocidade, distancia, litros;
    scanf("%f", &horas);
    scanf("%f", &velocidade);

    distancia = horas * velocidade;
    litros = distancia/12;
    printf("%.3f\n", litros);

    return 0;
}
