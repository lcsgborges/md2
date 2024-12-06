#include <stdio.h>

// fibonacci = 1 1 2 3 5 8 13 21 34 ...
//         n = 1 2 3 4 5 6 7  8  9  ...   

int fibonacci(int numero){

    int fib = 1;

    if (numero == 1 || numero == 2) return fib;
    
    else {
        fib = fibonacci(numero - 1) + fibonacci(numero - 2);
        return fib;
    }
}

int main(){

    int num1, valor;

    printf("Calculando Fibonacci\nDigite um número: ");
    scanf("%d", &num1);

    valor = fibonacci(num1);

    printf("O termo n = %d, representa o %d na sequência de Fibonacci.\n", num1, valor);

    return 0;
}