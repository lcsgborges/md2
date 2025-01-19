#include <stdio.h>

int calcularDigito(int cpf[], int peso[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += cpf[i] * peso[i];
    }
    int digito = soma % 11;
    if (digito < 2) {
        return 0;
    } else {
        return 11 - digito;
    }
}

int calcularDigitoISBN(int isbn[]) {
    int soma = 0;
    for (int i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            soma += isbn[i];
        } else {
            soma += isbn[i] * 3;
        }
    }
    int digito = soma % 10;
    
    return (digito == 0) ? 0 : 10 - digito;
}

int main() {
    int opcao;
    printf("Escolha o tipo de cálculo:\n");
    printf("1 - Calcular CPF\n");
    printf("2 - Calcular ISBN\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        long long cpf;
        printf("Digite o número do CPF (apenas os 9 primeiros dígitos): ");
        scanf("%lld", &cpf);
        int cpfArray[11];
        for (int i = 8; i >= 0; i--) {
            cpfArray[i] = cpf % 10;
            cpf /= 10;
        }
        int peso1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
        int peso2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
        int digito1 = calcularDigito(cpfArray, peso1, 9);
        cpfArray[9] = digito1;
        int digito2 = calcularDigito(cpfArray, peso2, 10);
        cpfArray[10] = digito2;
        printf("\nCPF Completo: ");
        for (int i = 0; i < 11; i++) {
            printf("%d", cpfArray[i]);
        }
        printf("\n");
        printf("Dígitos verificadores do CPF: %d, %d\n", digito1, digito2);
    }
    else if (opcao == 2) {
        long long isbn;
        printf("\nDigite o número do ISBN (apenas os 12 primeiros dígitos): ");
        scanf("%lld", &isbn);
        int isbnArray[13];
        for (int i = 11; i >= 0; i--) {
            isbnArray[i] = isbn % 10;
            isbn /= 10;
        }
        int digito = calcularDigitoISBN(isbnArray);
        isbnArray[12] = digito;
        printf("\nISBN Completo: ");
        for (int i = 0; i < 13; i++) {
            printf("%d", isbnArray[i]);
        }
        printf("\n");
        printf("Dígito verificador do ISBN: %d\n", digito);
    }
    else {
        printf("\nOpção inválida!\n");
    }
    return 0;
}