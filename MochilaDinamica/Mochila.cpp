#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>

/*Guilherme Moreira Rodrigues 20160105205
trabalho Mochila dinâmica A.P.A*/



using namespace std;

int MochilaDinamica(int n, int M, int pesos[], int valores[])
{
    int matr[n+1][M+1];
    int i, j;
//criando tabela ixj
   for (i=0;i<= n;i++)  {
       for (j=0;j<=M;j++)   {
           if (i==0||j==0) {
               matr[i][j] = 0;
           }
           else if (pesos[i-1]<=j) {
                 matr[i][j] = max(matr[i-1][j],valores[i-1] + matr[i-1][j-pesos[i-1]]);
           }
           else {
                 matr[i][j] = matr[i-1][j];
           }
       }
   }
return matr[n][M];
}

int main(void)
{
    int M;
    int n;
//--------ler arquivo-----------
    int ord[100000];
    string file;
    cout << "Digite o nome da instacia com .txt: ";
    cin >> file;
    ifstream in(file);
    char numero[10];
    int fim = 0;
    while(!in.eof()){
        in >> numero;
        ord[fim] = atoi(numero);
        fim++;
    }
    n = ord[0];
    M = ord[1];

    int pesos[n];
    int valores[n];
    int j =0;

	for (int i=2; i < 2*n+2; i = i+2)
	{
		pesos[j] = ord[i];
	
		valores[j] = ord[i+1];
		
		j++;
	}

    cout << "Valor: " <<  MochilaDinamica(n,M,pesos,valores) << endl;
    return 0;
}
