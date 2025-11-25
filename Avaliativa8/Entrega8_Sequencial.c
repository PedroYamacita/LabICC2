#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf(" %d", &N);
    int *vetor = (int *)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &vetor[i]);
    }

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
            for (int j = 0; j < N; j++)
            {
                if (alvo == vetor[j])
                {
                    if (j != n)
                    {
                        encontrado = 1;
                        break;
                    }
                }
            }
            if (encontrado)
            {
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