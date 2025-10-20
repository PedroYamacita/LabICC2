#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_MERGE 32

void QuickSort(int *vetor, int inicio, int fim);
void ShellSort(int *vetor, int tamanho);
void RadixSort(int vetor[], int tamanho);

int main()
{
    int seed = 12345;
    int tamanho;

    scanf(" %d", &tamanho);
    int *vetor = (int *)calloc(tamanho, sizeof(int));

    char formato[10];
    scanf(" %s", formato);

    if (strncmp(formato, "random", 3) == 0)
    {
        for (int i = 0; i < tamanho; i++)
        {

            int numero_aleatorio = get_random(&seed, tamanho);

            vetor[i] = numero_aleatorio;
        }
    }
    else if (strncmp(formato, "sorted", 3) == 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            vetor[i] = i + 1;
        }
    }
    else if (strncmp(formato, "reverse", 3) == 0)
    {
        int j = tamanho;
        for (int i = 0; i < tamanho; i++)
        {
            vetor[i] = j;
            j--;
        }
    }
    int metodo;
    scanf(" %d", &metodo);
    switch (metodo)
    {
    case 1:
        QuickSort(vetor, 0, tamanho);
        break; 
    case 2:
        ShellSort(vetor, tamanho);
        break;
    case 3:
        RadixSort(vetor, tamanho);
        break;
    }

    init_crc32();
    uint32_t saida = crc32(0, vetor, tamanho * sizeof(int));
    printf("%08X", saida);
    free(vetor);
    return 0;
}

void QuickSort(int *vetor, int inicio, int fim)
{
    int meio = (inicio + fim) / 2;

    // Escolhe o pivo
    int pivo = vetor[meio];
    int i = inicio, j = fim - 1;

    // Percorre pelo vetor diversas vezes comparando os elementos com o pivo
    while (i <= j)
    {
        while (pivo > vetor[i])
            i++;
        while (pivo < vetor[j])
            j--;

        // Realiza a troca
        if (i <= j)
        {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;

            i++;
            j--;
        }
    }
    // Faz chamadas de recorrencia para garantir a ordenacao
    if (j > inicio)
        QuickSort(vetor, inicio, j + 1);
    if (i < fim)
        QuickSort(vetor, i, fim);
}


void ShellSort(int *vetor, int tamanho) {
    // Sequência de Knuth: h = 3h + 1
    int h = 1;
    while (h < tamanho / 3)
        h = 3 * h + 1;
    
    while (h >= 1) {
        for (int i = h; i < tamanho; i++) {
            // Marca o elemento de comparacao
            int chave = vetor[i];
            int j = i;
            
            // Realiza a ordenacao dos elementos distantes por h
            while (j >= h && vetor[j - h] > chave) {
                vetor[j] = vetor[j - h];
                j -= h;
            }

            // Seleciona o novo elemento de comparacao
            vetor[j] = chave;
        }
        // Diminui o gap
        h /= 3;
    }
}

// Particiona o array com base no bit atual (mask).
int ParticaoPorBit(int *vetor, int inicio, int fim, int mask) {
    int i = inicio;
    int j = fim;
    
    while (i <= j) {
        // Encontra o primeiro elemento a esquerda com o bit '1'
        while (i <= j && (vetor[i] & mask) == 0) {
            i++;
        }
        
        // Encontra o primeiro elemento a direita com o bit '0'
        while (i <= j && (vetor[j] & mask) != 0) {
            j--;
        }

        // Se os ponteiros nao se cruzaram, troca os elementos para particionar
        if (i < j) {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }
    
    // Retorna o indice onde termina o grupo com bit 0 e começa o grupo com bit 1
    return i;
}

// Ordena o array recursivamente bit a bit (do mais significativo ao menos significativo).
void RadixSortBinario(int *vetor, int inicio, int fim, int mask) {
    if (inicio >= fim || mask == 0) {
        return;
    }
    
    // Particiona o array com base no bit atual
    int pivo = ParticaoPorBit(vetor, inicio, fim, mask);
    
    // Passa para o proximo bit (mask >> 1)
    int proximaMask = mask >> 1;
    
    // Chama recursivamente para a secao '0' (esquerda do pivo)
    RadixSortBinario(vetor, inicio, pivo - 1, proximaMask);
    
    // Chama recursivamente para a secao '1' (direita do pivo)
    RadixSortBinario(vetor, pivo, fim, proximaMask);
}

void RadixSort(int *vetor, int tamanho) {
    if (tamanho <= 1)
        return;

    // Acha o maior elemento para determinar o bit mais significativo
    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    // Determina a mascara do bit mais significativo (potencia de 2)
    int mask = 1;
    // O loop garante que mask seja a menor potencia de 2 maior ou igual a (max + 1)
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1; 

    // Chama o algoritmo recursivo
    RadixSortBinario(vetor, 0, tamanho - 1, mask);
}