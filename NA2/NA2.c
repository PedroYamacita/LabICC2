//Dupla: Leonardo Kenzo Tanaka e Pedro Teidi de Sá Yamacita

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcao para encriptografar a mensagem
void Encriptografar(char* plaintext);

int main(void){

    //Lendo a palavra a ser criptografada
    char* plaintext = (char*)calloc(1000, sizeof(char));
    if(plaintext == NULL){
        return 1;
    }
    scanf(" %[^\n\r]", plaintext);
    plaintext = realloc(plaintext, (strlen(plaintext) + 1) * sizeof(char));

    Encriptografar(plaintext);

    free(plaintext);

    return 0;
}

//Funcao que encriptografa e printa o texto cifrado
void Encriptografar(char* plaintext){
    int textLength = strlen(plaintext);

    //Encriptografa o texto
    for(int i = 0; i < textLength; i++){
        plaintext[i]++;
    }

    printf("%s", plaintext);
}