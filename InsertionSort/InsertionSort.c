/*Guilherme Moreira Rodrigues 20160105205

A.P.A

Insertion Sort
*/





#include <stdio.h>
#include <stdlib.h>



void InsertionSort(int vec[], int tam){

	int atual, k;
	
	for(int i = 1; i < tam; i++){
		atual = vec[i];
		k = i - 1;
		while ((k >= 0) && (vec[k] > atual)){
		vec[k + 1] = vec[k];
		k--;
	
		}

		vec[k + 1] = atual;	
	}
}



int main(){
	
	int i;
	int seq = 0;
	int tam;
	
	printf("Digite o tamanho do vetor\n");
		scanf("%d", &tam);
	
	int vec[tam];

	printf("Digte a sequencia que sera armazenada no vetor\n");
		
		for(i = 0; i < tam; i++){
			scanf("%d", &seq);
			vec[i] =  seq;
		}
	printf("O vetor inicial eh: ");
		for(i = 0; i < tam; i++){
			printf("\n%d", vec[i]);		
		}
		
	InsertionSort(vec, tam);
	printf("\nO vetor final eh: ");

		for(i = 0; i < tam; i++){
			printf("\n%d\n", vec[i]);
		}	
		
	
return 0;
}
