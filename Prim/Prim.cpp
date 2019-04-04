#include <stdio.h>
#include <stdlib.h>
#define INF 9999
#define V 4

/*Guilherme Moreira Rodrigues 20160105205
A.P.A - UFPB
*/

#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

#define V 9

void PRIM(int G[V][V]){
  int a=0;//aresta
  int s[V];

  memset(s, 0, sizeof(s)); 
  s[0] = 1;

  int x;//linha
  int y;//coluna

  cout << "Aresta" << " - " << "Peso"<<endl;

  while(a < V - 1){
    int min =10000;
      x = 0;
      y = 0;
      int i,j;

      for (i = 0; i < V; i++){
        if (s[i]){
            for (j = 0; j < V; j++){
              if (!s[j] && G[i][j]){
                  if (min > G[i][j]){
                      min = G[i][j];
                      x = i;
                      y = j;
                  }
              }
          }
        }
      }
      cout << x <<  " - " << y << "  = " << G[x][y];
      cout << endl;
      s[y] = 1;
      a++;
    }
}

int main () {

    int G[V][V] = {{0, 4, 0, 4, 0, 2, 0, 8, 1},
                      {4, 0, 8, 13, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 3, 9, 14, 0, 0, 0},
                      {2, 0, 0, 9, 0, 10, 0, 11, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 3, 0, 6, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 9, 0, 5, 6, 7, 5}};

    

    PRIM(G);

  return 0;
}
