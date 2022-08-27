//Gabriel Henrique Almeida Silva-RA:
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char car;
    int peso;
}Cell;

Cell *aloca(Cell *p, int tam){

    p = malloc(tam*sizeof(Cell));//Alocando dinamicamente

    return p;
}
void Atribui(Cell *p, int i,int tam);
int Soma(Cell *x, int tam, int a);
void Imprime(int s);

void Atribui(Cell *p, int i,int tam){
    for(i=0;i<tam;i++){
        printf("Escreva o caractere %d: \n",i);//Atribuindo os valores nos indices de caractere
        scanf("%c", &p[i].car);
        getchar();

        printf("Escreva o peso do caractere %d: \n",i);//Atribuindo os valores nos indices de peso
        scanf("%d", &p[i].peso);
        getchar();
    }
}

int Soma(Cell *x, int tam, int a){
    if(tam == 0){
        if(x[tam].car == x[tam+1].car || x[tam].car == x[tam-1].car ){//Condição da soma caso o valor de x seja consecutivo com o indice atual +1 ou -1
            a = x[tam].peso + a;
            return a;//Retornando caso a condição de parada for consecutiva
        }else{
        return a;//Retornando caso a condição de parada não for consecutiva
    }
    }else{
        if(x[tam].car == x[tam+1].car || x[tam].car == x[tam-1].car ){//Condição da soma caso o valor de x seja consecutivo com o indice atual +1 ou -1
            a = x[tam].peso + a;
            tam--;
            Soma(x,tam,a);//Retornando caso o valor seja consecutivo 
        }else{
            tam--;
            Soma(x,tam,a);//Retornando caso o valor não seja consecutivo 
        }
    }

}

void Imprime(int s){
    if(s == 0){
        printf("Nao existe nenhum elemento consecutivo na sequencia");//imprimindo o valor caso não tenha sequencias consecutivas
    }else{
        printf("O valor da soma dos elementos da faixa que sao consecutivos: %d", s);//mostrando o valor da soma
    }
}

int main(){
    int t,i,soma=0;
    Cell *vet;
    
    printf("Qual o tamanho do vetor? \n");//Solicitando o tamanho do vetor para o usuario
    scanf("%d",&t);
    getchar();

    vet = aloca(vet,t);//Alocando dinamicamente

    Atribui(vet,0,t);//Atribuindo os valores nos indices

    soma = Soma(vet,t--,0);//Fazendo a condição da soma

    free(vet);//Desalocando

    Imprime(soma);//imprimindo o valor

    return 0;
}