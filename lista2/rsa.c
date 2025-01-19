#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int euclidesExtendido(int e, int z) {
    int r1 = e, r2 = z;   
    int s1 = 1, s2 = 0;    
    int t1 = 0, t2 = 1;    
    while (r2 != 0) {
        int q = r1 / r2;    
        int r = r1 % r2;    
        int s = s1 - q * s2; 
        int t = t1 - q * t2; 
        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }
    if (r1 != 1) {
        return -1; 
    }
    if (s1 < 0) {
        s1 = s1 + z;
    }
    return s1; 
}

int letraParaNumero(char letra) {
    letra = toupper(letra); 
    if (letra >= 'A' && letra <= 'Z') {
        int numero = letra - 'A' + 11; 
        if (numero < 11) {
            numero = numero + 26; 
        }
        return numero;
    } else {
        return -1; 
    }
}

long long criptografar(long long M, int e, int n) {
    long long C = 1;
    for (int i = 0; i < e; i++) {
        C = (C * M) % n;
    }
    while(C < 11){
        C += 26;
    }
    while (C > 36)
        C -= 26;
    return C;
}

int main(){
    int p, q, n, z, e, d;

    printf("Digite o valor do número primo 'p': ");
    scanf("%d", &p);
    printf("\nDigite o valor do número primo 'q': ");
    scanf("%d", &q);
    n = p * q;
    printf("N = p * q -> N = %d\n", n);
    z = (p - 1) * (q - 1);
    printf("Z = (p-1)*(q-1) -> Z = %d\n", z);
    printf("Digite um número 'e' em que 1 < e < z e seja coprimo de z: ");
    scanf("%d", &e);
    d = euclidesExtendido(e, z);
    printf("D = %d\n", d);

    char frase[100];
    long long C;

    printf("\nDigite uma palavra (somente letras): ");
    getchar(); 
    fgets(frase, 100, stdin); 

    printf("\nTexto criptografado: ");
    for (int i = 0; frase[i] != '\0'; i++) {
        int numero = letraParaNumero(frase[i]);
        if (numero != -1) { 
            C = criptografar(numero, e, n);
            printf("%lld", C); 
        } 
    }
    printf("\n");
    return 0;
}