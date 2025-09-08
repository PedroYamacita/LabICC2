#include <stdio.h>

int main() {
    int n, k;
    int resultado = 1;
    int i;
    
    // Leitura dos valores de entrada
    scanf("%d", &n);

    scanf("%d", &k);
    
    // Validação das entradas
    if (n <= 0 || n > 99) {
        return 1;
    }
    
    if (k <= 0) {
        return 1;
    }
    
    // Cálculo de n^k mod 1000 de forma iterativa
    for (i = 0; i < k; i++) {
        resultado = (resultado * n) % 1000;
    }
    
    // Saída do resultado (sem zeros à esquerda)
    printf("%d\n", resultado);
    
    return 0;
}