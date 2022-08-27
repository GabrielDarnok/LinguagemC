/*Nome: VÍTOR LUÍS DA SILVA                 || RA: 2760482121016
  Nome: GABRIEL HENRIQUE DE ALMEIDA SILVA   || RA: 2760482121017
*/

#include <stdio.h>
int main(){
    int i,k=0,j=0,cont=0,y,x,z;/*declarando as variaveis*/
    char s,Vet[30];

    printf("escreva algo de ate 30 caracteres\n");/*salvando os caracteres no vetor*/
    while((s=getchar() )!='\n'){
        Vet[k]= s;
        k++;
    }
    Vet[k]='\0';/*comparando as letras*/
    for(x=0;x<k;x++){
        for(y=x+1;y<k;y++){
            if(Vet[x] == Vet[y]){
                for (z=y;z < k;z++){
                    Vet[z] = Vet[z+1];
                }
                k--;
            }   
        }
    }
    printf("valor de letras diferentes e de %d ", k);/*devolvendo os valore*/
     
    return 0;
}