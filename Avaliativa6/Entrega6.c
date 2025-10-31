#include <stdlib.h>
#include <stdio.h>
#include "util.h"
// Seed global para ser usada nas duas funções
int seed = 12345;

// Função que ordena o vetor
void FisherYatesShuffle(int *vector, int N, int *vezes)
{
    int ordenado = 1;
    // Verifica se esta ordenado
    for (int i = 0; i < N - 1; i++)
    {
        if (vector[i] > vector[i + 1])
        {
            ordenado = 0;
            break;
        }
    }
    // Se esta ordenado, interrompe a função
    if (ordenado)
    {
        return;
    }

    // Realizar o shuffle
    for (int i = N - 1; i > 0; i--)
    {
        int j = get_random(&seed, i) - 1;
        vector[i] = vector[i] + vector[j];
        vector[j] = vector[i] - vector[j];
        vector[i] = vector[i] - vector[j];
    }
    // Ponteiro responsavel por contar o numero de ocorrencias da recursão
    (*vezes)++;
    FisherYatesShuffle(vector, N, vezes);
}

int main()
{
    int N, quantasVezes = 0;
    int vetor[100];
    int *vezes;
    vezes = &quantasVezes;
    scanf(" %d", &N);

    // Criar vetor de numeros aleatórios
    for (int i = 0; i < N; i++)
    {

        int numero_aleatorio = get_random(&seed, N);

        vetor[i] = numero_aleatorio;
    }
    // Chamar a funçaõ
    FisherYatesShuffle(vetor, N, vezes);

    // Printar saída
    printf("%d\n", *vezes);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", vetor[i]);
    }
}