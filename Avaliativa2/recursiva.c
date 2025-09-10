#include <stdio.h>
#include <math.h>

int Potenciacao(int n, int k);

int main(){
    int n, k, resultado;

    //Le os valores de n e k dentro da faixa
    scanf(" %d %d", &n, &k);

    if(n < 0 || n > 99 || k < 0 || k > 1000000000){
        return 0;
    }

    //Calcula a potenciacao e printa os 3 ultimos digitos
    resultado = Potenciacao(n, k);

    printf("%d", resultado);
    
    return 0;
}

int Potenciacao(int n, int k){

    //Usando o metodo dividir para conquistar
    if(k == 1){
        return n;
    }
    else if(k == 0){
        return 1;
    }
    int potencia = Potenciacao(n, k / 2);

    //Usa o mod de 1000 para retornar somente os 3 ultimos digitos
    if(k % 2 == 0){
        return ((potencia * potencia) % 1000);
    }

    else if(k % 2 == 1){
        return ((potencia * potencia * n) % 1000);
    }
}