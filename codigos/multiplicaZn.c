#include <stdio.h>  

void soma_zn(int n){
    printf("\nTabela Z_%d da multiplicação modular: \n\n", n);

    printf("    ");
    for (int i = 0; i < n; i++){
        printf("%3d", i);
    }
    printf("\n");

    printf("   x");
    for(int i = 0; i < n; i++){
        printf("---");
    }
    printf("\n");

    for (int i = 0; i<n; i++){
        printf("%3d|", i);
        for(int j = 0; j < n; j++){
            printf("%3d", (i*j) % n);
        }
        printf("\n");
    }
}


int main(){

    int n;

    printf("Digite o valor de 'n' para gerar a tabela de sua multiplicação modular: ");
    scanf("%d", &n);

    soma_zn(n);

    return 0;
}