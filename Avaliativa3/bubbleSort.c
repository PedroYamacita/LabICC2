#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ContadorLetras(char *nome, int quantLetras);
void BubbleSort(char array[], int tamanhoArray, int *comparacao, int *trocas);

int main(){
    char nome[1000], *comunidade, listaNomesUsp[100003], listaNomesExterna[100003];
    int contadorLetras, nomesUsp = 0, nomesExterna = 0;
    int comparacaoUsp = 0, trocasUsp = 0;
    int comparacaoExterna = 0, trocasExterna = 0;

    //Le todas as strings ate EOF
    while(fgets(nome, sizeof(nome), stdin)){
        contadorLetras = 0;

        //Conta a quantidade de letras no nome
        int quantLetras = ContadorLetras(nome, contadorLetras);
        
        //Limpa a string para verificar qual comunidade ele pertence
        strtok(nome, "-");
        comunidade = strtok(NULL, "\n");
        if(comunidade == NULL) continue; 
        comunidade++;

        //Verifica em qual lista deve inserir
        if(strncmp(comunidade, "usp", 3) == 0){
            listaNomesUsp[nomesUsp] = (char)quantLetras;
            nomesUsp++;
        }
        if(strncmp(comunidade, "externa", 8) == 0){
            listaNomesExterna[nomesExterna] = (char)quantLetras;
            nomesExterna++;
        }
    }
    
    //Printa a lista da USP ordenada
    BubbleSort(listaNomesUsp, nomesUsp, &comparacaoUsp, &trocasUsp);
    printf("USP - [");
    for(int i = 0; i < nomesUsp; i++){
        if(i == nomesUsp - 1){
            printf("%d]\n", listaNomesUsp[i]);
            continue;
        }
        printf("%d, ", listaNomesUsp[i]);
    }

    printf("Comparações: %d, Trocas: %d\n\n", comparacaoUsp, trocasUsp);


    //Printa a lista externa ordenada
    BubbleSort(listaNomesExterna, nomesExterna, &comparacaoExterna, &trocasExterna);
    printf("Externa - [");
    for(int i = 0; i < nomesExterna; i++){
        if(i == nomesExterna - 1){
            printf("%d]\n", listaNomesExterna[i]);
            continue;
        }
        printf("%d, ", listaNomesExterna[i]);
    }

    printf("Comparações: %d, Trocas: %d\n", comparacaoExterna, trocasExterna);

    return 0;
}

//Funcao recursiva que retorna a quantidade de letras do nome
int ContadorLetras(char *nome, int quantLetras){

    //Passa por todos os caracteres da string
    char letra = nome[0];

    //Verificacoes e contador de letras 
    if(letra == '-' || letra == '\0'){
        return quantLetras;
    }
    if(isalpha(letra)){
        quantLetras++;
    }

    //Chamada recursiva
    return ContadorLetras(nome + 1, quantLetras);
}

//Funcao para realizar bubble sort
void BubbleSort(char array[], int tamanhoArray, int *comparacao, int *trocas){
    char auxiliar;
    *comparacao = 0;
    *trocas = 0;
    
    //Verifica quantos passos deve realizar
    for(int i = 0; i < tamanhoArray; i++){

        //Itera por todo o array e realiza a troca se necessaria
        for(int j = 0; j < tamanhoArray - i - 1; j++){
            (*comparacao)++;
            if(array[j] > array[j + 1]){
                auxiliar = array[j + 1];
                array[j + 1] = array[j];
                array[j] = auxiliar; 
                (*trocas)++;
            }
        }
    }
}