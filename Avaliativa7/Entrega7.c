#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO
{
    int data;
    struct NO *proximo;
} NO;

int data_para_inteiro(char *data);
void QuickSort(int *datas_inteiras, int inf, int sup);
int busca_binaria(int *datas_inteiras, int tamanho, int alvo);
int hash(int chave, int tamanho_table);
void free_hash_table(NO **table, int tamanho_table);

int main()
{
    int N;
    scanf(" %d", &N);

    int tamanho_table = N;

    char (*datas)[11] = calloc(N, sizeof(char[11]));
    int *datas_inteiras = calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf(" %s", datas[i]);
        datas_inteiras[i] = data_para_inteiro(datas[i]);
    }

    int Q;
    scanf(" %d", &Q);

    char (*datas_alvo)[11] = calloc(Q, sizeof(char[11]));
    int *alvos = calloc(Q, sizeof(int));

    for (int i = 0; i < Q; i++)
    {
        scanf(" %s", datas_alvo[i]);
        alvos[i] = data_para_inteiro(datas_alvo[i]);
    }

    int algoritmo;
    scanf(" %d", &algoritmo);

    switch (algoritmo)
    {
    case 1:
        QuickSort(datas_inteiras, 0, N - 1);

        for (int i = 0; i < Q; i++)
        {
            if (busca_binaria(datas_inteiras, N, alvos[i]))
            {
                printf("ENCONTRADA\n");
            }
            else
            {
                printf("NAO_ENCONTRADA\n");
            }
        }
        break;

    case 2:

        NO **table = calloc(tamanho_table, sizeof(NO *));

        for (int i = 0; i < N; i++)
        {
            int chave = datas_inteiras[i];
            int index = hash(chave, tamanho_table);

            NO *novo_no = (NO *)calloc(1, sizeof(NO));
            novo_no->data = chave;

            novo_no->proximo = table[index];
            table[index] = novo_no;
        }

        for (int i = 0; i < Q; i++)
        {
            int alvo = alvos[i];
            int index = hash(alvo, tamanho_table);
            int encontrado = 0;

            NO *atual = table[index];
            while (atual != NULL)
            {
                if (atual->data == alvo)
                {
                    encontrado = 1;
                    break;
                }
                atual = atual->proximo;
            }
            if (encontrado)
            {
                printf("ENCONTRADA\n");
            }
            else
            {
                printf("NAO_ENCONTRADA\n");
            }
        }
        free_hash_table(table, tamanho_table);
        break;

    case 3:

        for (int i = 0; i < Q; i++)
        {
            int encontrado = 0;
            for (int j = 0; j < N; j++)
            {
                if (strcmp(datas[j], datas_alvo[i]) == 0)
                {
                    encontrado = 1;
                    break;
                }
            }
            if (encontrado)
            {
                printf("ENCONTRADA\n");
            }
            else
            {
                printf("NAO_ENCONTRADA\n");
            }
        }
    }

    free(datas);
    free(datas_inteiras);
    free(datas_alvo);
    free(alvos);
}

int data_para_inteiro(char *data)
{
    int dia, mes, ano;
    sscanf(data, "%d-%d-%d", &dia, &mes, &ano);

    return (ano * 10000 + mes * 100 + dia);
}

void QuickSort(int *datas_inteiras, int inf, int sup)
{
    int meio = (inf + sup) / 2;
    int pivo;
    if (datas_inteiras[inf] < datas_inteiras[meio] && datas_inteiras[meio] < datas_inteiras[sup])
    {
        pivo = datas_inteiras[meio];
    }
    else if (datas_inteiras[meio] < datas_inteiras[inf] && datas_inteiras[inf] < datas_inteiras[sup])
    {
        pivo = datas_inteiras[inf];
    }
    else
    {
        pivo = datas_inteiras[sup];
    }
    int i = inf;
    int j = sup;

    do
    {
        while (datas_inteiras[i] < pivo)
        {
            i++;
        }
        while (datas_inteiras[j] > pivo)
        {
            j--;
        }
        if (i <= j)
        {
            int aux;
            aux = datas_inteiras[i];
            datas_inteiras[i] = datas_inteiras[j];
            datas_inteiras[j] = aux;
            i++;
            j--;
        }
    } while (i < j);
    if (j > inf)
        QuickSort(datas_inteiras, inf, j);
    if (i < sup)
        QuickSort(datas_inteiras, i, sup);
}

int busca_binaria(int *datas_inteiras, int tamanho, int alvo)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (datas_inteiras[meio] == alvo)
        {
            return meio;
        }
        if (datas_inteiras[meio] < alvo)
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

int hash(int chave, int tamanho_table)
{
    unsigned int posicao = chave % tamanho_table;

    return posicao;
}

void free_hash_table(NO **table, int tamanho_table)
{
    for (int i = 0; i < tamanho_table; i++)
    {
        NO *atual = table[i];
        while (atual != NULL)
        {
            NO *aux = atual;
            atual = atual->proximo;
            free(aux);
        }
    }
    free(table);
}