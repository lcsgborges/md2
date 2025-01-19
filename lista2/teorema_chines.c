#include <stdio.h>

long long mdc(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long inverso(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    
    if (m == 1) 
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) 
        x1 += m0;
    return x1;
}

long long teoremaChinesDoResto(int n, long long a[], long long m[]) {
    long long M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }
    long long x = 0;
    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long inv = inverso(Mi, m[i]);
        x += a[i] * Mi * inv;
    }
    return x % M;
}

int main() {
    int n;
    printf("Digite o número de equações (até 4): ");
    scanf("%d", &n);

    if (n < 1 || n > 4) {
        printf("Número de equações inválido. Deve ser entre 1 e 4.\n");
        return 1;
    }
    printf("\nVocê está resolvendo o sistema de congruências do tipo:\n");
    for (int i = 0; i < n; i++) 
        printf("x ≡ a[%d] (mod m[%d])\n", i + 1, i + 1);

    long long a[4], m[4];
    
    for (int i = 0; i < n; i++) {
        printf("\nDigite o valor de a[%d]: ", i + 1);
        scanf("%lld", &a[i]);
        printf("Digite o valor de m[%d]: ", i + 1);
        scanf("%lld", &m[i]);
    }
    long long resultado = teoremaChinesDoResto(n, a, m);
    long long M = 1;
    for (int i = 0; i < n; i++) 
        M *= m[i];
        
    printf("\n\nSolução do sistema de congruências: x ≡ %lld (mod %lld)\n", resultado, M);

    return 0;
}