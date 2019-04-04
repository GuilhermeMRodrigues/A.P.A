/*Guilherme Moreira Rodrigues 20160105205
A.P.A
Dijkstra*/

#include "dijkstra.h"


 
#define MAX 100

void dijkstra(int graph[V][V], int src)
{
     int dist[V];

     bool sptSet[V];

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     dist[src] = 0;


     for (int count = 0; count < V-1; count++)
     {

       int u = minDistance(dist, sptSet);


       sptSet[u] = true;


       for (int v = 0; v < V; v++)


         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }


     printSolution(dist, V);
}



int main(){

 int graph[V][V] =   {{0, 4, 0, 4, 0, 2, 0, 8, 1},
                      {4, 0, 8, 13, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 3, 9, 14, 0, 0, 0},
                      {2, 0, 0, 9, 0, 10, 0, 11, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 3, 0, 6, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 9, 0, 5, 6, 7, 5}};

    dijkstra(graph, 0);

    return 0;
}
