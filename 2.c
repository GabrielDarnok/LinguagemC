/*Nome: VÍTOR LUÍS DA SILVA                 || RA: 2760482121016
  Nome: GABRIEL HENRIQUE DE ALMEIDA SILVA   || RA: 2760482121017
*/
#include <stdio.h>
int main(){
    /*Armazenando os Valores dos vetores*/
    int num_seq_v1,num_seq_v2,i,x,y;
    printf("Informe a quantidade total de numeros da primeira sequencia(max 50).\n");
    scanf("%d", &num_seq_v1);
    printf("Informe a quantidade total de numeros da segundasequencia(max 50).\n");
    scanf("%d", &num_seq_v2);
    int v1[num_seq_v1],v2[num_seq_v2],uniao[num_seq_v1+num_seq_v2],tamanho=num_seq_v1+num_seq_v2;
    printf("Informe os numeros da primeira sequencia respeitando a quantidade total informada.\n");
    for(i=0;i < num_seq_v1;i++){
        scanf("%d", &v1[i]);
    }
    printf("Informe os numeros da segunda sequencia respeitando a quantidade total informada.\n");
    for(i=0;i < num_seq_v2;i++){
        scanf("%d", &v2[i]);
    }
    /*Incrementando o vetor de união*/
    for(i=0;i<num_seq_v1; i++){
        uniao[i] = v1[i];     
    }
    for(i=0;i<num_seq_v2; i++){
        uniao[i+num_seq_v1]= v2[i];
    }
    /*Eliminando os valores iguais*/
    for(x=0;x<tamanho;x++){
        for(y=x+1;y<num_seq_v1+num_seq_v2;y++){
            if(uniao[x] == uniao[y]){
                for (int k=y;k < tamanho;k++){
                    uniao[k] = uniao[k+1];
                }
                tamanho--;
            }   
        }
    }
    /*Printando o resultado Final*/
    for(i=0;i<tamanho;i++){
        printf("%d ", uniao[i]);
    }

    return 0;
}