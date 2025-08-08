#include <stdio.h>
#include <string.h>

void Encriptografar(char* plaintext);

int main(void){
    char* plaintext;
    scanf(" %[^\n]", plaintext);

    Encriptografar(plaintext);

    return 0;
}

void Encriptografar(char* plaintext){
    for(int i = 0; i < strlen(plaintext); i++){
        plaintext[i]++;
    }
    
    printf("%s", plaintext);
}