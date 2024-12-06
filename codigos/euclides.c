#include <stdio.h>

int euclides(int a, int b){

    while (b != 0){
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a; // se b = 0, a vira mdc
}

int main(){

    int a,b;

    printf("Digite dois números inteiros positivos para calcular o MDC entre eles: \n");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0){
        printf("Os números devem ser positivos");
        return 1;
    }

    int mdc = euclides(a,b);

    printf("O MDC de %d e %d é %d.\n", a, b, mdc);

    return 0;
}