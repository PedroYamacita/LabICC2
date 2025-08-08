//Dupla: Leonardo Kenzo Tanaka e Pedro Teidi de Sa Yamacita

#include <stdio.h>
#include <stdlib.h>

float* AdicionarNotas(int numeroAlunos);
void PrintarInformacoes(float* notaAlunos, int numeroAlunos);

int main(void){

    //Verifica se o numero de alunos eh valido
    int numeroAlunos;
    scanf(" %d", &numeroAlunos);
    if(numeroAlunos <= 0){
        return 0;
    }

    //Cria um array das notas dos alunos
    float* notaAlunos = AdicionarNotas(numeroAlunos);
    if(notaAlunos == NULL){
        free(notaAlunos);
        return 0;
    }
    
    PrintarInformacoes(notaAlunos, numeroAlunos);

    free(notaAlunos);
    
    return 0;
}

//Adiciona as notas de cada aluno em um array
float* AdicionarNotas(int numeroAlunos){
    float* notaAlunos = (float*)calloc(numeroAlunos, sizeof(float));
    if(notaAlunos == NULL){
        return NULL;
    }

    //Adiciona as notas de todos os alunos
    for (int i = 0; i < numeroAlunos; i++){
        scanf(" %f", &notaAlunos[i]);

        //Verifica se a nota esta entre 0 e 10
        if(notaAlunos[i] < 0 || notaAlunos[i] > 10){
            printf("Nota fora do intervalo.");
            return NULL;
        }
    }

    return notaAlunos; 
}

//Printa a quantidade de aprovados, a maior nota e a media
void PrintarInformacoes(float* notaAlunos, int numeroAlunos){
    int aprovados = 0;
    float mediaNota = 0;
    float maiorNota = notaAlunos[0];

    //Percorre todo o array calculando todas as informacoes
    for(int i = 0; i < numeroAlunos; i++){
        if(notaAlunos[i] >= 5){
            aprovados++;
        }
        if(notaAlunos[i] > maiorNota){
            maiorNota = notaAlunos[i];
        }
        mediaNota += notaAlunos[i];
    }
    mediaNota /= numeroAlunos;

    //Printa todas as informacoes formatadas
    printf("Foram %d aprovado(s). Maior nota = %.2f. Nota média = %.2f.", aprovados, maiorNota, mediaNota);
}