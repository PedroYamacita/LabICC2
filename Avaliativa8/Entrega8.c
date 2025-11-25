#include <stdio.h>
#include <stdlib.h>

int binary_search(int *vetor, int tamanho, int alvo, int excluir);
void QuickSort(int *vetor, int inf, int sup);

int main()
{
    int N;
    scanf(" %d", &N);
    int *vetor = (int *)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &vetor[i]);
    }
    QuickSort(vetor, 0, N - 1);

    int M;
    scanf(" %d", &M);
    int *somas = (int *)calloc(M, sizeof(int));
    int alvo;
    for (int i = 0; i < M; i++)
    {
        scanf(" %d", &somas[i]);
    }

    for (int m = 0; m < M; m++)
    {
        int encontrado = 0;
        for (int n = 0; n < N; n++)
        {
            alvo = somas[m] - vetor[n];
            if (binary_search(vetor, N, alvo, n))
            {
                encontrado = 1;
                break;
            }
        }
        if (encontrado)
        {
            printf("S\n");
        }
        else
        {
            printf("N\n");
        }
    }

    free(vetor);
    free(somas);
    return 0;
}

int binary_search(int *vetor, int tamanho, int alvo, int excluir)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (vetor[meio] == alvo)
        {
            if (meio != excluir)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (vetor[meio] < alvo)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }
    // Não encontrou
    return 0;
}

void QuickSort(int *vetor, int inf, int sup)
{
    int meio = (inf + sup) / 2;
    int pivo;
    if (vetor[inf] < vetor[meio] && vetor[meio] < vetor[sup])
    {
        pivo = vetor[meio];
    }
    else if (vetor[meio] < vetor[inf] && vetor[inf] < vetor[sup])
    {
        pivo = vetor[inf];
    }
    else
    {
        pivo = vetor[sup];
    }
    int i = inf;
    int j = sup;

    do
    {
        while (vetor[i] < pivo)
        {
            i++;
        }
        while (vetor[j] > pivo)
        {
            j--;
        }
        if (i <= j)
        {
            int aux;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    } while (i < j);
    if (j > inf)
        QuickSort(vetor, inf, j);
    if (i < sup)
        QuickSort(vetor, i, sup);
}