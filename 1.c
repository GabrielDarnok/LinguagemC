/*Nome: VÍTOR LUÍS DA SILVA                 || RA: 2760482121016
  Nome: GABRIEL HENRIQUE DE ALMEIDA SILVA   || RA: 2760482121017
*/
#include <stdio.h>
int main(){
    int tamanho,x,i,result = -1;/*declarando variavel*/
    printf("Digite o tamanho do vetor.(MAX 10)\n");/*salvando o tamanho do vetor*/
    scanf("%d",&tamanho);
    printf("Digite os elementos do seu vetor de tamanho %d.\n", tamanho);/*salvando os valores do vetor*/
    int Vet[tamanho];
    
    for(i=0;i<tamanho;i++){
        scanf("%d", &Vet[i]);
    }
    
    printf("Digite o valor chave.\n");
    scanf("%d",&x);/*salvando o valor chave*/
    
    for(i=0;i<tamanho;i++){/*laço para encontrar o valor chave*/
        if(result == -1){
            if (x == Vet[i]){
                printf("O indice no qual se encontra o elemento %d e o %d", x,i);/*indica a posiçao do valor chave*/
                result = i;
            }
            if (x != Vet[i] && i == tamanho-1){printf("Valor nao encontrado!.");}/*indica se o valor chave nao estiver no vetor*/
        }
    }
    return 0;
}