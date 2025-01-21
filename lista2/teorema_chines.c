#include <stdio.h>

int calculaMDC(int x, int y) {
    return (y == 0) ? x : calculaMDC(y, x % y);
}

int calculaInversoModular(int x, int mod) {
    int modOriginal = mod, temp, quociente;
    int inverso0 = 0, inverso1 = 1;

    if (mod == 1)
        return 0;

    while (x > 1) {
        quociente = x / mod;
        temp = mod;
        mod = x % mod;
        x = temp;
        temp = inverso0;
        inverso0 = inverso1 - quociente * inverso0;
        inverso1 = temp;
    }

    return (inverso1 < 0) ? inverso1 + modOriginal : inverso1;
}

int resolveCongruencia(int coeficiente, int constante, int mod) {
    int divisor = calculaMDC(coeficiente, mod);

    if (constante % divisor != 0) {
        printf("Sem solucao para a congruencia %dx ≡ %d (mod %d)\n", coeficiente, constante, mod);
        return -1;
    }

    coeficiente /= divisor;
    constante /= divisor;
    mod /= divisor;

    int coeficienteInverso = calculaInversoModular(coeficiente, mod);

    return (coeficienteInverso * constante) % mod;
}

int aplicaTeoremaChines(int coeficientes[], int constantes[], int mods[], int numEquacoes) {
    int produtoMods = 1;
    int resultadoFinal = 0;

    for (int i = 0; i < numEquacoes; i++) {
        produtoMods *= mods[i];
    }

    for (int i = 0; i < numEquacoes; i++) {
        int produtoParcial = produtoMods / mods[i];
        int inverso = calculaInversoModular(produtoParcial, mods[i]);
        resultadoFinal += constantes[i] * produtoParcial * inverso;
    }

    return resultadoFinal % produtoMods;
}

int main() {
    int numEquacoes;
    printf("Digite o numero de equacoes (ate 4): \n");
    scanf("%d", &numEquacoes);

    int coeficientes[4], constantes[4], mods[4];

    printf("\nDigite os valores para cada equacao na forma ax ≡ b (mod m):\n");
    for (int i = 0; i < numEquacoes; i++) {
        printf("Equacao %d:\n", i + 1);
        scanf("%d %d %d", &coeficientes[i], &constantes[i], &mods[i]);
        printf("%dx ≡ %d (mod %d)\n", coeficientes[i], constantes[i], mods[i]);
    }

    for (int i = 0; i < numEquacoes; i++) {
        constantes[i] = resolveCongruencia(coeficientes[i], constantes[i], mods[i]);
        if (constantes[i] == -1) {
            return 1;
        }
    }

    int solucaoFinal = aplicaTeoremaChines(coeficientes, constantes, mods, numEquacoes);
    int produtoTotal = 1;

    for (int i = 0; i < numEquacoes; i++) {
        produtoTotal *= mods[i];
    }

    printf("\nA solucao do sistema e x ≡ %d (mod %d)\n", solucaoFinal, produtoTotal);

    return 0;
}
