/* Guilherme Moreira 20160105205

A.P.A

Heap Sort

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int vector[MAX];

void heapSort(int *V, int tam){
	int i, aux;
	for(i = (tam - 1)/2; i >= 0; i--){
		criaHeap(V, i, tam-1);
	}
	for(i = tam-1; i >= 1; i--){
		aux = V[0];	
		V[0] = V[i];
		V[i] = aux;
		criaHeap(V, 0, i - 1);
	}
}

void criaHeap(int *V, int i, int f){
	int aux = V[i];
	int j = i * 2 + 1;
	while(j <= f){
		if(j < f){
			if(V[j] < V[j + 1]){
				j = j + 1;			
			}	
		}
		if(aux < V[j]){
			V[i] = V[j];	
			i = j;
			j = 2 * i + 1;
		}else{
			j = f + 1;		
		}	
	
	}
	V[i] = aux;
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

	heapSort(vector, MAX);

	printf("O vetor organizado eh: ");
	exibeVector(vector, MAX);
return 0;
}
