#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Briqnuedos da AABK
typedef struct brinquedo
{
    int id;
    char cor[10];
    float comprimento;
    float nota;
} BRINQUEDO;

BRINQUEDO *ItemCriar(int id, char *cor, float comprimento, float nota);

// Lista Sequencial Dinamica
typedef struct lista
{
    BRINQUEDO **elementos;
    int tamanho;
} LISTA;

LISTA *ListaCriar(int brinquedos);
LISTA *ListaAdicionar(LISTA *lista, BRINQUEDO *brinquedo, int posicao);
void ListaFree(LISTA **item);

// Algoritmos de ordenação
void BubbleSort(LISTA *lista);
void QuickSort(LISTA *lista, int inicio, int fim);
void MergeSort(LISTA *lista, int inicio, int fim, BRINQUEDO **auxiliar);
void InsertionSort(LISTA *lista);

// Função auxiliar
bool PodeTrocar(BRINQUEDO *item1, BRINQUEDO *item2);

int main()
{
    int brinquedos, comando;
    float nota, comprimento;
    char cor[10];
    scanf(" %d", &brinquedos);
    LISTA *lista = ListaCriar(brinquedos);

    // Leitura dos brinquedos
    for (int i = 0; i < brinquedos; i++)
    {
        scanf(" %s %f %f", cor, &comprimento, &nota);

        BRINQUEDO *item = ItemCriar(i, cor, comprimento, nota);
        ListaAdicionar(lista, item, i);
    }

    // Seleciona qual Sort utilizar para ordenacao
    scanf(" %d", &comando);
    switch (comando)
    {
    case 1:
        BubbleSort(lista);
        break;
    case 2:
        InsertionSort(lista);
        break;
    case 3:
        BRINQUEDO **auxiliar = (BRINQUEDO **)calloc(lista->tamanho, sizeof(BRINQUEDO *));
        MergeSort(lista, 0, lista->tamanho, auxiliar);
        free(auxiliar);
        break;
    case 4:
        QuickSort(lista, 0, lista->tamanho);
        break;
    }

    // Printa a lista ordenada
    for (int i = 0; i < brinquedos; i++)
    {
        printf("%d;", lista->elementos[i]->id);
    }
    printf("\n");

    ListaFree(&lista);
    return 0;
}

void BubbleSort(LISTA *lista)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        bool estaOrdenado = true;
        for (int j = 0; j < lista->tamanho - 1; j++)
        {
            if (PodeTrocar(lista->elementos[j], lista->elementos[j + 1]))
            {
                BRINQUEDO *aux = lista->elementos[j];
                lista->elementos[j] = lista->elementos[j + 1];
                lista->elementos[j + 1] = aux;
                estaOrdenado = false;
            }
        }
        if (estaOrdenado)
            break;
    }
}

void QuickSort(LISTA *lista, int inicio, int fim)
{
    int meio = (inicio + fim) / 2;

    BRINQUEDO *pivo = lista->elementos[meio];
    int i = inicio, j = fim - 1;
    while (i <= j)
    {
        while (PodeTrocar(pivo, lista->elementos[i]))
            i++;
        while (PodeTrocar(lista->elementos[j], pivo))
            j--;

        if (i <= j)
        {
            BRINQUEDO *aux = lista->elementos[i];
            lista->elementos[i] = lista->elementos[j];
            lista->elementos[j] = aux;

            i++;
            j--;
        }
    }
    if (j > inicio)
        QuickSort(lista, inicio, j + 1);
    if (i < fim)
        QuickSort(lista, i, fim);
}

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

void InsertionSort(LISTA *lista)
{
    int j;
    for (int i = 1; i < lista->tamanho; i++)
    {
        // Pega uma chave fixa para comparar
        BRINQUEDO *chave = lista->elementos[i];
        j = i - 1;

        // Desloca todos os elementos maiores que o brinquedo chave uma casa para a frente
        while (j >= 0 && PodeTrocar(lista->elementos[j], chave))
        {
            lista->elementos[j + 1] = lista->elementos[j];
            j--;
        }

        // Insere o brinquedo na posicao correta ordenada
        lista->elementos[j + 1] = chave;
    }
}

bool PodeTrocar(BRINQUEDO *item1, BRINQUEDO *item2)
{
    if (item1 && item2)
    {
        // Verifica a ordem alfabetica da cor
        int cmp = strncmp(item1->cor, item2->cor, 10);
        if (cmp > 0)
            return true;
        else if (cmp < 0)
            return false;

        // Verifica o comprimento
        if (item1->comprimento > item2->comprimento)
            return true;
        else if (item1->comprimento < item2->comprimento)
            return false;

        // Verifica a nota
        if (item1->nota < item2->nota)
            return true;
        else if (item1->nota > item2->nota)
            return false;

        // Verifica o id do item
        if (item1->id > item2->id)
            return true;
            
        return false;    
    }
    return false;
}

LISTA *ListaCriar(int brinquedos)
{
    LISTA *lista = (LISTA *)calloc(1, sizeof(LISTA));
    lista->elementos = (BRINQUEDO **)calloc(brinquedos, sizeof(BRINQUEDO *));
    if (lista->elementos == NULL)
    {
        printf("Falta memoria!\n");
        free(lista);
        lista = NULL;

        return NULL;
    }
    lista->tamanho = brinquedos;

    return lista;
}

LISTA *ListaAdicionar(LISTA *lista, BRINQUEDO *item, int posicao)
{
    if (lista != NULL && item != NULL)
    {
        lista->elementos[posicao] = item;
        return lista;
    }
    return NULL;
}

void ListaFree(LISTA **lista)
{
    if (lista && *lista)
    {
        for (int i = 0; i < (*lista)->tamanho; i++)
        {
            free((*lista)->elementos[i]);
        }
        free((*lista)->elementos);
        free(*lista);
        *lista = NULL;
    }
}

BRINQUEDO *ItemCriar(int id, char *cor, float comprimento, float nota)
{
    BRINQUEDO *item = (BRINQUEDO *)calloc(1, sizeof(BRINQUEDO));
    item->id = id;
    strcpy(item->cor, cor);
    item->comprimento = comprimento;
    item->nota = nota;

    return item;
}
