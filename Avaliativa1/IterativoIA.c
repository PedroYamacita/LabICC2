#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
 
// Função para verificar se é palíndromo 
int eh_palindromo(char *str) { 
    char processada[1000]; 
    int j = 0; 
     
    // Processa a string: considera apenas caracteres alfanuméricos 
    for(int i = 0; str[i] != '\0'; i++) { 
        char c = str[i]; 
        if(isalnum(c)) { 
            processada[j++] = tolower(c); 
        } 
    } 
    processada[j] = '\0'; 
     
    int len = j; 
     
    // Strings vazias ou com 1 caractere são palíndromos 
    if(len <= 1) { 
        return 1; 
    } 
     
    // Verifica se é palíndromo comparando caracteres das extremidades 
    for(int i = 0; i < len / 2; i++) { 
        if(processada[i] != processada[len - 1 - i]) { 
            return 0; 
        } 
    } 
     
    return 1; 
} 
 
int main() { 
    char linha[1000]; 
     
    // Lê linha por linha até EOF 
    while(fgets(linha, sizeof(linha), stdin) != NULL) { 
        // Remove o '\n' do final se existir 
        int len = strlen(linha); 
        if(len > 0 && linha[len-1] == '\n') { 
            linha[len-1] = '\0'; 
        } 
         
        // Verifica se é palíndromo e imprime resultado 
        if(eh_palindromo(linha)) { 
            printf("Sim\n"); 
        } else { 
            printf("Não\n"); 
        } 
    } 
     
    return 0; 
}