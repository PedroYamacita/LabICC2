// Dupla Leonardo Kenzo e Pedro Yamacita
#include <stdio.h>

int main()
{

    int dia, mes, ano, bissexto = 0;
    // vetor de meses para acesso nas saidas. Batata no indice 0 para os meses poderem ser acessados diretamente pelo seu numero no calendario normal
    const char meses[13][20] = {"batata", "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    scanf(" %d", &dia);
    scanf(" %d", &mes);
    scanf(" %d", &ano);
    // definir se é bissexto
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        printf("%d é bissexto.", ano);
        bissexto = 1;
    }
    else
    {
        printf("%d não é bissexto.", ano);
    }

    // Tratar fevereiro
    if (mes == 2)
    {
        if (bissexto && dia <= 29 && dia >= 1)
        {
            printf(" Existe o dia %d em %s.", dia, meses[mes]);
        }
        else if (bissexto == 0 && dia <= 28 && dia >= 1)
        {
            printf(" Existe o dia %d em %s.", dia, meses[mes]);
        }
        else
        {
            printf(" Não existe o dia %d em %s.", dia, meses[mes]);
        }
    }

    // tratar meses com 31 dias (1, 3, 5, 7, 8, 10, 12)
    else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dia <= 31 && dia >= 1)
        {
            printf(" Existe o dia %d em %s.", dia, meses[mes]);
        }
        else
        {
            printf(" Não existe o dia %d em %s.", dia, meses[mes]);
        }
    }

    // Outros meses com 30 dias
    else
    {
        if (dia <= 30 && dia >= 1)
        {
            printf(" Existe o dia %d em %s.", dia, meses[mes]);
        }
        else
        {
            printf(" Não existe o dia %d em %s.", dia, meses[mes]);
        }
    }
    return 0;
}