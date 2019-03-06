/* Guilherme Moreira 20160105205

A.P.A

Heap Sort

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int vector[MAX];


void troca(int *x, int *y){ 
   int aux;
   aux=*x;
   *x=*y;
   *y=aux;
}


int Pai(int i){
    int x = (i-1)/2;
    return x;
}

int FilhoEsquerdo(int i){
    int x = (2*i)+1;

    return x;
}


int FilhoDireito(int i){
    int x = (2*i)+2;

    return x;
}



void MaxHeapfy(int *V, int N, int i){
	int ladoEsquerdo = FilhoEsquerdo(i);
	int ladoDireito = FilhoDireito(i);
	int maior = i;
	
	int HEAP = N - Pai(i) - 1;
	
	if(ladoEsquerdo <= HEAP && V[ladoEsquerdo]>V[maior])
		maior = ladoEsquerdo;
	
	
	if(ladoDireito <= HEAP && V[ladoDireito]>V[maior])
		maior = ladoDireito;
	
	if(maior != i){
		troca(&V[i], &V[maior]);
		MaxHeapfy(HEAP, V, maior);
	
	
	}
}




void BuildMaxHeap(int *V){
	
	int i = 0;
	int n = MAX;

	for(i = (MAX/2) -1; i >= 0; i--)
		MaxHeapfy(n, V, i);

}




void heapSort(int *V){
	BuildMaxHeap(V);
	int i = 0;
	
	for(i = MAX - 1; i>=0; i--){
		troca(&V[0], &V[i]);
		MaxHeapfy(i, V, 0);

	}
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

	heapSort(vector);

	printf("O vetor organizado eh: ");
	exibeVector(vector, MAX);
return 0;
}
