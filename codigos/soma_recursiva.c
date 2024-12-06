#include <stdio.h>

int soma(int n){
    if (n == 1){
        printf("1");
        return 1;
    }

    int soma1 = soma(n-1); // soma os números até n-1
    printf(" + %d", n); 
    return soma1 + n; // soma total
}

int main(){
    int n;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    printf("Soma dos números de 1 até %d: \n", n);
    int x = soma(n);
    printf(" = %d\n", x);

    return 0;
}