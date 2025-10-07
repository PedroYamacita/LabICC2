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
void MergeSort(LISTA *lista, int inicio, int fim);
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
        QuickSort(lista, 0, lista->tamanho);
        break;
    case 3:
        MergeSort(lista, 0, lista->tamanho);
        break;
    case 4:
        InsertionSort(lista);
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
void Merge(LISTA *lista, int inicio, int meio, int fim)
{
    int quantElem1 = meio - inicio + 1;
    int quantElem2 = fim - meio;

    // Cria lista temporarias
    LISTA *listaTemp1 = ListaCriar(quantElem1);
    LISTA *listaTemp2 = ListaCriar(quantElem2);

    for (int i = 0; i < listaTemp1->tamanho; i++)
    {
        listaTemp1->elementos[i] = lista->elementos[inicio + i];
    }
    for (int i = 0; i < listaTemp2->tamanho; i++)
    {
        listaTemp2->elementos[i] = lista->elementos[meio + 1 + i];
    }

    printf("Entrou no Conquistar\n");

    // Junta as duas listas ordenadamente comparando os primeiros elementos de cada
    int i = 0, j = 0;
    while (i < quantElem1 && j < quantElem2)
    {
        if (PodeTrocar(listaTemp1->elementos[i], listaTemp2->elementos[j]))
        {
            lista->elementos[inicio] = listaTemp2->elementos[j];
            j++;
        }
        else
        {
            lista->elementos[inicio] = listaTemp1->elementos[i];
            i++;
        }
        inicio++;
    }

    // Se sobrou elementos, adiciona na lista principal
    if (i < quantElem1)
    {
        for (int k = i; k < quantElem1; k++)
        {
            lista->elementos[inicio] = listaTemp1->elementos[k];
            inicio++;
        }
    }
    else if (j < quantElem2)
    {
        for (int k = j; k < quantElem2; k++)
        {
            lista->elementos[inicio] = listaTemp2->elementos[k];
            inicio++;
        }
    }

    printf("Entrou no fim do Merge\n");
    // Libera as listas temporarias
    ListaFree(&listaTemp1);
    ListaFree(&listaTemp2);
}

void MergeSort(LISTA *lista, int inicio, int fim)
{
    // Condicao de parada da recursao
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        printf("Entrou no MergeSort\nInicio: %d, Meio: %d, Fim: %d\n", inicio, meio, fim);
        // Dividir
        MergeSort(lista, inicio, meio);
        MergeSort(lista, meio + 1, fim);

        // Conquistar
        Merge(lista, inicio, meio, fim);
    }
    printf("Terminou o Merge Sort\n");
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

        // Se for igual ou estiver na ordem
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
