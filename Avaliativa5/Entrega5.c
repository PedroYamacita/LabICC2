#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void QuickSort(int *vetor, int inicio, int fim);
// void MergeSort(int *vetor);
// void HeapSort(int *vetor);

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
        // MergeSort(vetor);
        break;
    case 3:
        // HeapSort(vetor);
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

    int pivo = vetor[meio];
    int i = inicio, j = fim - 1;
    while (i <= j)
    {
        while (pivo > vetor[i])
            i++;
        while (pivo < vetor[j])
            j--;

        if (i <= j)
        {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;

            i++;
            j--;
        }
    }
    if (j > inicio)
        QuickSort(vetor, inicio, j + 1);
    if (i < fim)
        QuickSort(vetor, i, fim);
}

/*
// Funcao auxiliar para o MergeSort
void Merge(LISTA *lista, int inicio, int meio, int fim, BRINQUEDO **auxiliar)
{
    // Copia a lista original na lista auxiliar
    for(int i = inicio; i <= fim; i++){
        auxiliar[i] = lista->elementos[i];
    }

    int posLista1 = inicio;
    int posLista2 = meio + 1;
    int posListaOriginal = inicio;

    // Junta as duas listas ordenadamente comparando os primeiros elementos de cada
    while (posLista1 <= meio && posLista2 <= fim)
    {
        if (!PodeTrocar(auxiliar[posLista1], auxiliar[posLista2]))
        {
            lista->elementos[posListaOriginal] = auxiliar[posLista1];
            posLista1++;
        }
        else
        {
            lista->elementos[posListaOriginal] = auxiliar[posLista2];
            posLista2++;
        }
        posListaOriginal++;
    }

    // Se sobrou elementos, adiciona na lista principal
    while(posLista1 <= meio){
        lista->elementos[posListaOriginal] = auxiliar[posLista1];
        posListaOriginal++;
        posLista1++;
    }
     while(posLista2 <= fim){
        lista->elementos[posListaOriginal] = auxiliar[posLista2];
        posListaOriginal++;
        posLista2++;
    }
}

void MergeSort(LISTA *lista, int inicio, int fim, BRINQUEDO **auxiliar)
{
    // Condicao de parada da recursao
    if (inicio < fim)
    {
        int meio = (int)(inicio + fim) / 2;
        // Dividir
        MergeSort(lista, inicio, meio, auxiliar);
        MergeSort(lista, meio + 1, fim, auxiliar);

        // Conquistar
        Merge(lista, inicio, meio, fim, auxiliar);
    }
}
*/