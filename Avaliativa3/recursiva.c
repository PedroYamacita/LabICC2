#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ContadorLetras(char *nome, int quantLetras);

int main(){
    int listaNomesUsp[100], listaNomesExterna[100], contadorLetras, nomesUsp = 0, nomesExterna = 0;
    char nome[100], *comunidade;

    //Le todas as strings ate EOF
    while(fgets(nome, sizeof(nome), stdin)){
        contadorLetras = 0;

        //Conta a quantidade de letras no nome
        int quantLetras = ContadorLetras(nome, contadorLetras);
        
        //Limpa a string para verificar qual comunidade ele pertence
        strtok(nome, "-");
        comunidade = strtok(NULL, "\n");
        comunidade++;

        //Verifica em qual lista deve inserir
        if(strncmp(comunidade, "usp", 3) == 0){
            listaNomesUsp[nomesUsp] = quantLetras;
            nomesUsp++;
        }
        if(strncmp(comunidade, "externa", 8) == 0){
            listaNomesExterna[nomesExterna] = quantLetras;
            nomesExterna++;
        }
    }

    //Printa a lista da USP e a externa
    printf("USP - [");
    for(int i = 0; i < nomesUsp; i++){
        if(i == nomesUsp - 1){
            printf("%d]\n", listaNomesUsp[i]);
            continue;
        }
        printf("%d, ", listaNomesUsp[i]);
    }

    printf("Externa - [");
    for(int i = 0; i < nomesExterna; i++){
        if(i == nomesExterna - 1){
            printf("%d]\n", listaNomesExterna[i]);
            continue;
        }
        printf("%d, ", listaNomesExterna[i]);
    }

    return 0;
}

//Funcao recursiva que retorna a quantidade de letras do nome
int ContadorLetras(char *nome, int quantLetras){

    //Passa por todos os caracteres da string
    char letra = nome[0];

    //Verificacoes e contador de letras
    if(!isalpha(letra) && letra != '-'){
        nome++;
    } 
    if(isalpha(letra)){
        quantLetras++;
        nome++;
    }
    if(letra == '-'){
        return quantLetras;
    }

    //Chamada recursiva
    ContadorLetras(nome, quantLetras);
}
