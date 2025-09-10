#include <stdio.h>

int main()
{
    int n, k, resultado = 1;

    //Leitura das variaveis
    scanf(" %d %d", &n, &k);
    if(n < 0 || n > 99 || k < 0 || k > 1000000000){
        return 1;
    }

    //Dividir para conquistar 
    if (k % 2 == 0)
    {
        for (int i = 0; i < k / 2; i++)
        {
            resultado = (resultado * n) % 1000;
        }
        printf("%d", (resultado * resultado) % 1000);
    }
    else
    {
        for (int i = 0; i < k / 2; i++)
        {
            resultado = (resultado * n) % 1000;
        }
        printf("%d", (resultado * resultado * n) % 1000);
    }
}