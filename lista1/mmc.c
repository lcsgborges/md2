#include <stdio.h>

int euclides(int a, int b){ // calculando mdc primeiro.

    while (b != 0){
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a; // se b = 0, a vira mdc
}

int calculo_mmc(int a, int b){
    int mdc = euclides(a,b);
    return (a * b / mdc); // fórmula mdc x mmc = a x b
}

int main(){
    int a,b;

    printf("Digite dois números inteiros positivos:\n");
    scanf("%d %d", &a, &b);

    int mmc = calculo_mmc(a,b);

    printf("O MMC de %d e %d é %d\n", a,b,mmc);

    return 0;
}