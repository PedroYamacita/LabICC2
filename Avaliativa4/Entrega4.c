#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Briqnuedos da AABK
typedef struct no
{
    int id;
    char cor[10];
    float comprimento;
    float nota;
    struct no *proximo;
    struct no *anterior;
} ITEM;
ITEM *item_criar(int id, char *cor, float comprimento, float nota);

// Lista a ser ordenada
typedef struct lista
{
    ITEM *inicio;
    ITEM *fim;
    int tamanho;
} LISTA;
LISTA *lista_criar();
LISTA *lista_adicionar(LISTA *lista, ITEM *brinquedo);

// Algoritmos de ordenação
void BubbleSort(LISTA *lista);
void SuickSort(LISTA *lista);
void MergeSort(LISTA *lista);
void InsertionSort(LISTA *lista);

// Função auxiliar
bool Troca(ITEM *item1, ITEM *item2);

int main()
{
    int brinquedos;
    float nota, comprimento;
    char cor[10];
    scanf(" %d", &brinquedos);
    LISTA *lista = lista_criar(brinquedos);

    for (int i = 0; i < brinquedos; i++)
    {
        scanf(" %s %f %f", cor, &comprimento, &nota);

        ITEM *brinquedo = item_criar(i, cor, comprimento, nota);
        lista_adicionar(lista, brinquedo);
    }
    return 0;
}

LISTA *lista_criar()
{
    LISTA *lista = (LISTA *)calloc(1, sizeof(LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

LISTA *lista_adicionar(LISTA *lista, ITEM *item)
{
    if (lista && item)
    {
        if (lista->tamanho == 0)
        {
            lista->inicio = item;
            lista->fim = item;
        }
        else
        {
            item->anterior = lista->fim;
            lista->fim->proximo = item;
            lista->fim = item;
        }
        lista->tamanho++;
        return lista;
    }

    return NULL;
}

ITEM *item_criar(int id, char *cor, float comprimento, float nota)
{
    ITEM *item = (ITEM *)calloc(1, sizeof(ITEM));
    item->proximo = NULL;
    item->anterior = NULL;
    item->id = id;
    strcpy(item->cor, cor);
    item->comprimento = comprimento;
    item->nota = nota;

    return item;
}

void BubbleSort(LISTA *lista)
{
    ITEM *itemAuxTroca = NULL;
    ITEM *itemAux = lista->inicio;
    bool estaOrdenado = false;
    for (int i = 0; i < lista->tamanho && !estaOrdenado; i++)
    {
        for (int j = 0; j < lista->tamanho - 1; j++)
        {
        }
    }
}