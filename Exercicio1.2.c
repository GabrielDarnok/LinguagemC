//Nome: Gabriel Henrique Almeida Silva RA:2760482121017
//Nome: Juan Silva Santos RA: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char Placa[8];
    char Marca[12];
    char Modelo[12];
} Carro;

void Insere(Carro *P,int tam);
void Procura(char k[],Carro *p,int q);
void Altera(char key[],Carro *p,int q);
void Imprime(char key[],Carro *p,int q);


void Insere(Carro *P,int tam){
    int i;
    
    for(i=0;i<tam;i++){
        printf("Digite a placa: \n");//Pegando a placa
        scanf("%s",&P[i].Placa);
        printf("Digite a marca: \n");//Pegando a marca
        scanf("%s",&P[i].Marca);
        printf("Digite a modelo: \n");//Pegando o modelo
        scanf("%s",&P[i].Modelo);
    }
}

void Procura(char k[],Carro *p,int q){
    FILE *arq;
    int i=0;

    arq = fopen("Carros.bin","rb");//Abre o arquivo para leitura
    if(arq==NULL){
        printf("\n-------Arquivo não encontrado-------\n");
    }else{
        printf("\n-------Arquivo aberto-------\n");
    }
    while(fread(p, sizeof(Carro), q, arq)){
        if(strcmp(k, p[i].Placa)== 0){//Caso encontrar mostra os valores
            printf("-------Informacoes do carro-------\n");
            printf("placa: %s \n", p[i].Placa);
            printf("marca: %s \n", p[i].Marca);
            printf("modelo: %s\n\n", p[i].Modelo);
            i++;
        }
    }
    fclose(arq);//Fecha o arquivo
}

void Altera(char key[],Carro *p,int q){
    FILE *arqB;
    int achou=0,i=0;

    arqB = fopen("Carros.bin","rb");
    if(arqB==NULL){
        printf("\n-------Arquivo não encontrado-------\n");
    }else{
        printf("\n-------Arquivo aberto-------\n");
    }
    while(fread(p, sizeof(Carro), q, arqB)){
        if(strcmp(key, p[i].Placa)== 0){//Caso encontrar a chave solicita uma nova marca e um novo modelo
            printf("-------Informacoes do carro-------\n");
            printf("Digite a marca: \n");
            scanf("%s", &p[i].Marca);
            printf("Digite o modelo: \n");
            scanf("%s", &p[i].Modelo);
            achou++;
            i++;
        }
    }
    fwrite(p, sizeof(Carro), q, arqB);//Salva as alterações
    fclose(arqB);//Fecha o arquivo
}

void Imprime(char key[],Carro *p,int q){
    FILE *arqB;
    int i=0;

    arqB = fopen("Carros.bin","rb");
    if(arqB==NULL){
        printf("\n-------Arquivo não encontrado-------\n");
    }else{
        printf("\n-------Arquivo aberto-------\n");
    }
    while(fread(p, sizeof(Carro), q, arqB)){
        if(strcmp(key, p[i].Placa)== 0){
            printf("-------Informacoes do carro-------\n");
            printf("placa: %s \n", p[i].Placa);
            printf("marca: %s \n", p[i].Marca);
            printf("modelo: %s\n\n", p[i].Modelo);
            i++;
        }
    }
    fclose(arqB);
}

int main(){
    FILE *arqB;
    Carro *A;
    int T,i,E;
    char chave[8],aux;

    arqB = fopen("Carros.bin","ab");


    printf("Quantidade de carros\n");//Pegando a quantidade de carros para fazer a alocação dinamica
    scanf("%d",&T);

    A = malloc (T * sizeof(Carro));

    Insere(A,T);//inserindo os valores

    fwrite(A, sizeof(Carro), T, arqB);//Salvando no arquivo
    fclose(arqB);//Fehcando o arquivo

    printf("Qual a placa do carro que deseja procurar no arquivo ?\n");//Solicitando a chave da busca
    scanf("%s", &chave);

    Procura(chave,A,T);//Buscando no arquivo

    printf("Deseja alterar algum campo? \n1-SIM\n2-NAO\n");
    scanf("%d",&E);

    if(E == 1){//Se quiser alterar realiza as funções
        printf("Qual a placa do carro para adiocionar um novo modelo e marca do carro no arquivo ?\n");
        scanf("%s", &chave);
        Altera(chave,A,T);//Escreve os parametros novos
        Imprime(chave,A,T);//Imprime os valores
    }

    return 0; 
}