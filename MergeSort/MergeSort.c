/*GUILHERME MOREIRA
20160105205
A.P.A
MERGESORT
*/


#include <stdio.h>

#include <stdlib.h>

#define MAX 10 // veriavel para definir o maximo de caracter do vector

int vector[MAX];//vetor com 10 indices 

void sort(int inicio, int fim) {
   int meio;
   
   if(inicio < fim) { //se inicio for menor que o meio
      meio = (inicio + fim) / 2; //acha o meio 
      sort(inicio, meio); //chama a função novamente, primeira metade
      sort(meio+1, fim);//chama a função novamente, segunda metade
      merge(vector, inicio, meio, fim);//chama o merge para combinar as duas metades;
   } else { 
      return;
   }   
}


void merge(int *vector, int inicio, int meio, int fim){
	int *vecAux, aux1, aux2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1; //tamanho do vetor 
	
	aux1 = inicio; //vetor primeira metade
	aux2 = meio+1; //vetor segunda metade
	
	vecAux = (int*) malloc(tamanho*sizeof(int)); //vetor combinado aux1 + aux2
	
	if(vecAux != NULL){//percorrendo o vetor a ser combinado
		for(i = 0; i < tamanho; i++){
			if(!fim1 && !fim2){
				if(vector[aux1] < vector[aux2])	//qual indice da posição é menor		
					vecAux[i] = vector[aux1++];//se for p1, vecAux[i] = o indice do aux1
				else
					vecAux[i] = vector[aux2++];//se for p2, vecAux[i] = o indice do aux2
				
				if(aux1>meio) // SE O VETOR ACABOU FIM = 1
					 fim1 = 1;
				if(aux2>fim) 
					fim2=1;
			}else{	
				if(!fim1) // SE ACABAR UM VETOR COPIA O QUE SOBROU DO OUTRO NO VETOR MAIOR
					vecAux[i] = vector[aux1++];
			
				else
					vecAux[i] = vector[aux2++];
			}			
		 }		
		for(j=0, k=inicio; j<tamanho; j++, k++) //JOGA OS DADOS DO VETOR aux no original
			vector[k] = vecAux[j]; 
	}
		
free(vecAux);
}

void exibeVector(int vec[], int tam) 
{ 
    int i; 
    for (i = 1; i <= tam; i++) 
        printf("%d ", vec[i]); 
    printf("\n"); 
} 






int main(){
	
	
	int seq;
	
	printf("Qual sera a sequencia armazenada no vetor?");
		
		for(int i = 1; i <= MAX; i++){
			scanf("%d", &seq);		
			vector[i] = seq;		
		}
	

	
	printf("O vetor inical eh: ");
		for(int i = 1; i <= MAX; i++){
			printf("\n%d", vector[i]);
	
		}
		
	
	
	sort(0, MAX);
	
	printf("\nVetor organizado:\n"); 
   	exibeVector(vector, MAX); 

return 0;

}


