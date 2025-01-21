#include <stdio.h>
#include <string.h>
#include <math.h>

int calcular_mdc(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int calcular_inverso_modular(int numero, int mod) {
    int mod_inicial = mod, valor_y = 0, valor_x = 1;
    while (numero > 1) {
        int quociente = numero / mod;
        int temp = mod;
        mod = numero % mod;
        numero = temp;
        temp = valor_y;
        valor_y = valor_x - quociente * valor_y;
        valor_x = temp;
    }
    if (valor_x < 0)
        valor_x += mod_inicial;
    return valor_x;
}

int caractere_para_numero(char caractere) {
    if (caractere >= 'A' && caractere <= 'Z') return caractere - 'A' + 11;
    if (caractere >= 'a' && caractere <= 'z') return caractere - 'a' + 11;
    return -1;
}

char numero_para_caractere(int codigo) {
    if (codigo >= 11 && codigo <= 36) return 'A' + (codigo - 11);
    return '?';
}

long long calcular_potencia_modular(long long base, long long exp, long long mod) {
    long long resultado = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            resultado = (resultado * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return resultado;
}

int main() {
    int primo_p, primo_q, chave_publica_e, tamanho_bloco;

    printf("Digite o número primo p: ");
    scanf("%d", &primo_p);
    printf("Digite o número primo q: ");
    scanf("%d", &primo_q);

    int numero_n = primo_p * primo_q;
    int valor_z = (primo_p - 1) * (primo_q - 1);

    printf("N = %d\n", numero_n);
    printf("Z = %d\n", valor_z);

    printf("Digite a chave pública E: ");
    scanf("%d", &chave_publica_e);
    printf("Digite o tamanho do bloco: ");
    scanf("%d", &tamanho_bloco);

    if (calcular_mdc(chave_publica_e, valor_z) != 1) {
        printf("Erro: a chave pública E não é coprima de Z(%d).\n", valor_z);
        return 1;
    }

    int chave_privada_d = calcular_inverso_modular(chave_publica_e, valor_z);

    printf("Chave pública: (E=%d, N=%d)\n", chave_publica_e, numero_n);
    printf("Chave privada: (D=%d, N=%d)\n", chave_privada_d, numero_n);

    char texto_mensagem[256];
    printf("Digite a mensagem a ser criptografada (apenas letras): ");
    scanf("%s", texto_mensagem);

    if (strlen(texto_mensagem) == 0) {
        printf("Erro: mensagem vazia.\n");
        return 1;
    }

    int blocos_texto[256];
    int tamanho_texto = strlen(texto_mensagem);

    printf("\nMensagem convertida em blocos:\n");
    for (int i = 0; i < tamanho_texto; i++) {
        blocos_texto[i] = caractere_para_numero(texto_mensagem[i]);
        if (blocos_texto[i] == -1) {
            printf("Erro: a mensagem contém caracteres inválidos.\n");
            return 1;
        }
        printf("%d ", blocos_texto[i]);
    }

    printf("\n\nbloco criptografado:\n");
    long long texto_criptografado[256];
    for (int i = 0; i < tamanho_texto; i++) {
        texto_criptografado[i] = calcular_potencia_modular(blocos_texto[i], chave_publica_e, numero_n);
        printf("%lld", texto_criptografado[i]);
    }

    printf("\n\nbloco descriptografado:\n");
    for (int i = 0; i < tamanho_texto; i++) {
        int texto_descriptografado = calcular_potencia_modular(texto_criptografado[i], chave_privada_d, numero_n);
        printf("%c", numero_para_caractere(texto_descriptografado));
    }

    printf("\n");
    return 0;
}
