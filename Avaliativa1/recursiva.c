// Dupla Leonardo Kenzo Tanaka e Pedro Teidi de Sá Yamacita
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TAM 100

bool palindromo(char *linha, int inicio, int fim){
    // significa que a recursao foi repetida com sucesso vezes os suficente para passar do meio da string, indicando um palindromo
    if (inicio >= fim)
        return true;
    // Não é palindromo
    if (linha[inicio] != linha[fim])
        return false;
    // chamada recursiva
    return palindromo(linha, inicio + 1, fim - 1);
}

int main(){
    char linha[TAM];
    char linhaLimpa[TAM];
    char letras;

    while (1){
        // verifica se a leitura da linha foi bem sucedida
        if (!fgets(linha, TAM, stdin))
            break;
        
            // verifica se chegou ao fim das entradas
        if (strncmp(linha, "EOF", 3) == 0)
            break;
        
            // contador do comprimento
        int comprimento = 0;
        for (int i = 0; linha[i] != '\0'; i++){
            
            letras = linha[i];
            // filtro de caracteres
            if (!(letras >= 'A' && letras <= 'Z') && !(letras >= 'a' && letras <= 'z') && !(letras >= '0' && letras <= '9')){
                continue;
            }
            // Passar todas as letras para minusculas se forem maiusculas
            if (letras <= 'Z' && letras >= 'A'){
                letras += 32;
            }
            
            // guardar as letras em uma linha limpa
            linhaLimpa[comprimento] = letras;
            comprimento++;
        }
        
        // fechar a string com \0
        linhaLimpa[comprimento] = '\0';
        if (palindromo(linhaLimpa, 0, comprimento - 1)){
            printf("Sim\n");
        }
        else{
            printf("Não\n");
        }
    }
    return 0;
}