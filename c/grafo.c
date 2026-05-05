// Daniele dos Santos Araújo - 20161070120229

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

typedef struct vertice {
  char nome;
} Vertice;

typedef struct aresta {
  int adjacente;
} Aresta;

typedef struct grafo {
  Vertice vertices[MAX_VERTICES];
  Aresta arestas[MAX_VERTICES][MAX_VERTICES];
} Grafo;

int main(void) {
  Grafo grafo;
  int linha;
  int coluna;

  grafo.vertices[0].nome = 'A';
  grafo.vertices[1].nome = 'B';
  grafo.vertices[2].nome = 'C';
  grafo.vertices[3].nome = 'D';
  grafo.vertices[4].nome = 'E';

  grafo.arestas[0][0].adjacente = 0;
  grafo.arestas[0][1].adjacente = 1;
  grafo.arestas[0][2].adjacente = 1;
  grafo.arestas[0][3].adjacente = 0;
  grafo.arestas[0][4].adjacente = 1;

  grafo.arestas[1][0].adjacente = 1;
  grafo.arestas[1][1].adjacente = 0;
  grafo.arestas[1][2].adjacente = 0;
  grafo.arestas[1][3].adjacente = 1;
  grafo.arestas[1][4].adjacente = 0;

  grafo.arestas[2][0].adjacente = 1;
  grafo.arestas[2][1].adjacente = 0;
  grafo.arestas[2][2].adjacente = 0;
  grafo.arestas[2][3].adjacente = 1;
  grafo.arestas[2][4].adjacente = 0;

  grafo.arestas[3][0].adjacente = 0;
  grafo.arestas[3][1].adjacente = 1;
  grafo.arestas[3][2].adjacente = 1;
  grafo.arestas[3][3].adjacente = 0;
  grafo.arestas[3][4].adjacente = 0;

  grafo.arestas[4][0].adjacente = 1;
  grafo.arestas[4][1].adjacente = 0;
  grafo.arestas[4][2].adjacente = 0;
  grafo.arestas[4][3].adjacente = 0;
  grafo.arestas[4][4].adjacente = 1;

  for (linha = 0; linha < MAX_VERTICES; linha++) {
    for (coluna = 0; coluna < MAX_VERTICES; coluna++) {
      if (grafo.arestas[linha][coluna].adjacente == 1) {
        printf("\n %c eh acente de %c", grafo.vertices[coluna].nome,
               grafo.vertices[linha].nome);
      }
    }
  }

  return 0;
}
