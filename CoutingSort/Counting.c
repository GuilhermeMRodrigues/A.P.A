/*GUILHERME MOREIRA 20160105205

A.P.A

COUTING SORT
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKET 100
#define MAX 10

int vector[MAX];

void coutingSort(int *V, int N){
	int buckets[MAX_BUCKET];
	int i, j, k;
	
	for(i = 0; i < MAX_BUCKET; i++)
		buckets[i] = 0;
	
	for(i =0; i < N; i++)
		buckets[V[i]]++;
	
	for(i = 0, j = 0; j < MAX_BUCKET; j++)
		for(k = buckets[j]; k > 0; k--)	
			V[i++] = j;

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

	coutingSort(vector, MAX);

	printf("O vetor organizado eh: ");
	exibeVector(vector, MAX);
return 0;
}
