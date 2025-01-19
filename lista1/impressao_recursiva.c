#include <stdio.h>

void imprime(int atual, int n){
    if (atual > n){
        return ;
    }

    printf("%d, ", atual);
    imprime(atual + 1 , n);
}

int main(){
    int n;

    printf("Digite o valor de n: \n");
    scanf("%d", &n);

    printf("Números naturais de 1 a %d: \n", n);
    imprime(1, n);
    printf("\n");

    return 0;
}