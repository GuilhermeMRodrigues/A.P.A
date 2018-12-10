/*Guilherme Moreira 20160105205

APA
Selection Sort

*/

#include <stdio.h>
#include <stdlib.h>	

void SelectionSort(int vec[], int tam){//fixa um posição e compara com todas as outras posições para encontrar o menor valor e troca a posição do menor com o maior
	
	int menor, aux;	
	
	for(int i = 0; i < tam-1; i++){
		menor = i;
		for(int k = i + 1; k < tam; k++){//vai para as proximas posições do vetor procurando o menor elemento em relação a i
			if(vec[menor] > vec[k])
				menor = k;		
					
		}
		if(i!=menor){ //troca a posicao atual pela menor posicao
			aux = vec[i];
			vec[i] = vec[menor];
			vec[menor] = aux;
		
		}
		
	
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
		
	SelectionSort(vec, tam);
	printf("\nO vetor final eh: ");

		for(i = 0; i < tam; i++){
			printf("\n%d\n", vec[i]);
		}	
		
	
return 0;
}
