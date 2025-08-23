#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define TAM 100

bool Palindromo(char *linha);

int main(){
    char linha[TAM];

    while(fgets(linha, TAM, stdin) != NULL){
        if(Palindromo(linha)){
            printf("Sim\n");
        }
        else{
            printf("Não\n");
        }
    }

    return 0;
}

bool Palindromo(char *linha){
    char linhaLimpa[TAM];
    int tamanhoLinhaLimpa = 0;

    //Processa a linha bruta em uma linha limpa para melhor analise de palindromo
    for(int i = 0; linha[i] != '\0'; i++){
        char caracter = linha[i];

        //Filtra somente os caracteres alfanumericos
        if (!(caracter >= 'A' && caracter <= 'Z') && !(caracter >= 'a' && caracter <= 'z') && !(caracter >= '0' && caracter <= '9')){
            continue;
        }
        //Converte todas as letras maiusculas em minusculas
        if (caracter <= 'Z' && caracter >= 'A'){
            caracter += 32;
        }

        //Passa todas as letras validas para a linha limpa
        linhaLimpa[tamanhoLinhaLimpa] = caracter;
        tamanhoLinhaLimpa++;
    }

    linhaLimpa[tamanhoLinhaLimpa] = '\0';

    for(int i = 0; i < strlen(linhaLimpa)/2; i++){
        if(linhaLimpa[i] != linhaLimpa[tamanhoLinhaLimpa - 1 - i]){
            return false;
        }
    }
    return true;
}
