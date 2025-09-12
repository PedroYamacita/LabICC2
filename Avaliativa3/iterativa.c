#include <stdio.h>
#include <string.h>

int tamanho_nome(char *nome);

int main()
{
    char linha[256];
    char *nome;
    char *publico;
    int tamanho;
    int USP[256];
    int EXTERNO[256];
    int i = 0, j = 0;
    // ler até encontra EOF
    while (fgets(linha, 256, stdin))
    {
        // adicionar \0 ao final da string
        linha[strcspn(linha, "\n")] = '\0';

        // separa a pimeira parte antes do '-' como nome
        nome = strtok(linha, "-");
        // verificar se deu certa a tokenizaçao
        if (!nome)
            continue;

        // tirar possiveis espaços à esquerda
        while (*nome == ' ')
            nome++;

        // substituir espaços no meio do nome por '-'
        nome[strcspn(nome, " ")] = '-';

        // como o espaço no meio foi ocupado por '-' podemos adicionar \0 ao final caso o nome seja composto
        nome[strcspn(nome, " ")] = '\0';

        // separa publico
        publico = strtok(NULL, "\0");
        if (!publico)
            continue;
        // tirar possiveis espaços à esquerda
        while (*publico == ' ')
            publico++;

        tamanho = tamanho_nome(nome);

        // adiciona o tamanho ao array correspondente
        if (strncmp(publico, "usp", 3) == 0)
        {
            USP[i] = tamanho;
            i++;
        }
        else if (strncmp(publico, "externa", 7) == 0)
        {
            EXTERNO[j] = tamanho;
            j++;
        }
    }

    // estrutura dos prints
    printf("USP - [");
    for (int k = 0; k < i; k++)
    {
        if (k == i - 1)
        {
            printf("%d", USP[k]);
        }
        else
        {
            printf("%d, ", USP[k]);
        }
    }
    printf("]\n");

    printf("Externa - [");
    for (int k = 0; k < j; k++)
    {
        if (k == j - 1)
        {
            printf("%d", EXTERNO[k]);
        }
        else
        {
            printf("%d, ", EXTERNO[k]);
        }
    }
    printf("]\n");

    return 0;
}

int tamanho_nome(char *nome)
{
    int tamanho = 0;
    for (int i = 0; nome[i] != '\0'; i++)
    {
        // pular espaçoes e '-' que adicionamos no caso do nome ser composto
        if (nome[i] != ' ' && nome[i] != '-')
            tamanho++;
    }
    return tamanho;
}