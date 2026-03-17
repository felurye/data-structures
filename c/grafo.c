// Daniele dos Santos Araújo - 20161070120229

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

struct vertice {
  char nome;
};

struct aresta {
  int adj;
};

struct grafo {
  struct vertice vertices[MAX_VERTICES];
  struct aresta arestas[MAX_VERTICES][MAX_VERTICES];
};

int main() {
  struct grafo g1;
  int i, j;

  g1.vertices[0].nome = 'A';
  g1.vertices[1].nome = 'B';
  g1.vertices[2].nome = 'C';
  g1.vertices[3].nome = 'D';
  g1.vertices[4].nome = 'E';

  // Adjacencias de A
  g1.arestas[0][0].adj = 0;
  g1.arestas[0][1].adj = 1;
  g1.arestas[0][2].adj = 1;
  g1.arestas[0][3].adj = 0;
  g1.arestas[0][4].adj = 1;

  // Adjacencias de B
  g1.arestas[1][0].adj = 1;
  g1.arestas[1][1].adj = 0;
  g1.arestas[1][2].adj = 0;
  g1.arestas[1][3].adj = 1;
  g1.arestas[1][4].adj = 0;

  // Adjacencias de C
  g1.arestas[2][0].adj = 1;
  g1.arestas[2][1].adj = 0;
  g1.arestas[2][2].adj = 0;
  g1.arestas[2][3].adj = 1;
  g1.arestas[2][4].adj = 0;

  // Adjacencias de D
  g1.arestas[3][0].adj = 0;
  g1.arestas[3][1].adj = 1;
  g1.arestas[3][2].adj = 1;
  g1.arestas[3][3].adj = 0;
  g1.arestas[3][4].adj = 0;

  // Adjacencias de E
  g1.arestas[4][0].adj = 1;
  g1.arestas[4][1].adj = 0;
  g1.arestas[4][2].adj = 0;
  g1.arestas[4][3].adj = 0;
  g1.arestas[4][4].adj = 1;

  for (i = 0; i < MAX_VERTICES; i++) {
    for (j = 0; j < MAX_VERTICES; j++) {
      if (g1.arestas[i][j].adj == 1) {
        printf("\n %c eh acente de %c", g1.vertices[j].nome,
               g1.vertices[i].nome);
      }
    }
  }

  return 0;
}
