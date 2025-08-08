// Dupla Leonardo Kenzo e Pedro Yamacita.
#include <stdio.h>
#include <string.h>

typedef struct cidade
{
    char nome[100];
    int populacao;
} Cidade;

int main()
{

    int nCidades, populacaoTemp;
    char cidadeTemp[100];

    scanf(" %d", &nCidades);
    if (nCidades > 10)
    {
        printf("n fora do intervalo.");
        return 0;
    }
    Cidade cidadeMaior;

    scanf(" %[^\n\r]", cidadeMaior.nome);
    scanf(" %d", &cidadeMaior.populacao);

    for (int i = 0; i < nCidades - 1; i++)
    {
        scanf(" %[^\n\r]", cidadeTemp);
        scanf(" %d", &populacaoTemp);
        if (populacaoTemp > cidadeMaior.populacao)
        {
            cidadeMaior.populacao = populacaoTemp;
            strcpy(cidadeMaior.nome, cidadeTemp);
        }
    }
    printf("%s %d", cidadeMaior.nome, cidadeMaior.populacao);
    return 0;
}