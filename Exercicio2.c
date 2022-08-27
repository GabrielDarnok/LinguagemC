//Gabriel Henrique Almeida Silva-RA:
//

#include <stdio.h>
#include <stdlib.h>

struct valor{
    int *vet,*v2;//declarando os ponteiros para alocação dinamica
    int n,n2;//declarando as variaveis para determinar o tamanho dos vetores
};

struct valor insere(struct valor x);
void ordena(struct valor x, int i, int j);
struct valor encontra(struct valor x,int i, int j,int k);
void imprime(struct valor x,int i);

struct valor insere(struct valor x){
    int i;
    
    printf("Digite o tamanho do vetor: \n");//solicitando o tamanho do vetor
    scanf("%d",&x.n);
    
    x.vet = malloc(x.n*sizeof(int));//alocando dinamicamente o primeiro vetor

    printf("Escreva os elementos do vetor\n");
    for(i=0;i<x.n;i++){
        printf("Escreva o valor da posicao %d\n", i);//solicitando os valores ao usuario
        scanf("%d",&x.vet[i]);
    }

    return x;
}

void ordena(struct valor x, int i, int j){
    int aux;

    for(i=0;i<x.n;i++){//Deixando vetor em ordem crescente
        for(j=0;j<x.n;j++){
            if(x.vet[i] < x.vet[j] && i != j){
                aux = x.vet[i];
                x.vet[i] = x.vet[j];
                x.vet[j] = aux;
            }
        }
    }

}

struct valor encontra(struct valor x,int i, int j,int k){
    int aux,*num,a,cont=0;
    x.n2=0;

    num = malloc(x.n *sizeof(int));//alocando dinamicamente o vetor auxiliar
    
    for(i=0;i<x.n;i++){//Verifica se o valor da soma é igual ao tamanho de algum dos valores do vetor, caso for adiciona 1 em aux
        aux=0;
        for(j=0;j<x.n;j++){
            for(k=j+1;k<x.n;k++){
                if(x.vet[i] == x.vet[j]+x.vet[k]){
                    aux++;
                }
            }
        }
        if(aux == 0){//executa quando não encontrar um numero que somado é igual ao do vetor
            num[x.n2] = x.vet[i];
            x.n2++;
        }
    }
    x.v2 = malloc(x.n2* sizeof(int));//aloca dinamicamente o segundo valor

    for(i=0;i<x.n2;i++){//atribui os valores encontrados no vetor auxiliar
        x.v2[i]=num[i];
        }

        free(num);//Desalocando

        return x;//retornando o tamanho do vetor
    }
    
void imprime(struct valor x,int i){
    printf("\nOs valores do primeiro vetor sao: ");//imprimindo os valores do primeiro vetor
    for(i=0;i<x.n;i++){
        printf("%d ", x.vet[i]);
    }
    printf("\n\nOs valores do segundo vetor sao: ");//imprimindo os valores do segundo vetor
    for(i=0;i<x.n2;i++){
        printf("%d ", x.v2[i]);
    }
    free(x.vet);//Desalocando
    free(x.v2);//Desalocando
}

int main(){
    
    struct valor x;
    
    x = insere(x); // função para inserir os valores
    
    ordena(x,0,0);//função para ordenar o vetor em ordem crescente

    x = encontra(x,0,0,0);// separar os valores com a devida condição
    
    imprime(x,0);//imprime os valores dos vetores

    return 0;
}