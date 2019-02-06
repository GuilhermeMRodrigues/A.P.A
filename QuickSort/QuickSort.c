/*GUILHERME MOREIRA
20160105205
A.P.A
MERGESORT
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int vector[MAX];

void quickSort(int *vector, int inicio, int fim){
	int aux;
	if(fim > inicio){ 
		aux = corte(vector, inicio, fim);//a posição do aux com a função que particiona
		quickSort(vector, inicio, aux-1);//elementos antes do pivo
		quickSort(vector, aux+1, fim);//elementos depois do pivo
	}
}


int corte(int *vector, int inicio, int final){
	int esquerda, direita, pivo, aux;
	esquerda = inicio;
	direita = final;
	pivo = vector[inicio];//pivo é a parte de inicio do vetor
	while(esquerda < direita){
		while(vector[esquerda] <= pivo)//anda com a esquerda ate achar um elemento que nao seja menor que o pivo
			esquerda++;	
		while(vector[direita] > pivo)//anda com  a direita enquanto ela é menor que o pivo

			direita--;

		if(esquerda < direita){ //se a esquerda for menor que a direita troca os dois de lugar
			aux = vector[esquerda];		
			vector[esquerda] = vector[direita];
			vector[direita] = aux;
				
		}
	}
	vector[inicio] = vector[direita];//recebe ultimo valor onde a direita para
	vector[direita] = pivo;//ultimo valor da direita recebe o pivo
	
	return direita;//retorna direita, onde todo mundo antes é menor e dps é maior
}


void exibeVector(int vec[], int tam) 
{ 
    int i; 
    for (i = 1; i <= tam; i++) 
        printf("\n%d ", vec[i]); 
    printf("\n"); 
} 




int main(){
	
	int seq;
	
	printf("Qual sera a sequencia armanazenada no vetor?\n");	
		for(int i = 1; i <= MAX; i++){
			scanf("%d", &seq);
			vector[i] = seq;		
		}

	quickSort(vector, 1, MAX);

	printf("O vetor organizado eh: ");
	exibeVector(vector, MAX);
return 0;
}
