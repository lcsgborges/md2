#include <stdio.h>

// 5! = 5 * 4 * 3 * 2 * 1 = 120
// n! = n * (n-1) * ... * 2 * 1 = K

int fatorial(int numero){

    int fat = 1;

    if (numero == 1 || numero == 0) {
        return fat; // Retorna 1 para 0! e 1!
    } else {
        fat = numero * fatorial(numero - 1); // Calcula o fatorial recursivamente
        return fat; // Retorna o resultado calculado
    }
}


int main(){

    int numero, valor;

    printf("Calculando Fatoriais\nDigite um número: \n");
    scanf("%d", &numero);

    valor = fatorial(numero);

    printf("Resposta: %d\n", valor);

    return 0;
}