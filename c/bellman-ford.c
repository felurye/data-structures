#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 8
#define INF 99999

typedef struct vertice {
  char nome[15];
  int custo;
  int ant;
} Vertice;

typedef struct aresta {
  int adj;
  int peso;
} Aresta;

typedef struct grafo {
  Vertice V[MAX_VERTICES];
  Aresta E[MAX_VERTICES][MAX_VERTICES];
} Grafo;

Grafo relaxa(Grafo g, int i, int j) {
  if (g.E[i][j].peso + g.V[i].custo < g.V[j].custo) {
    g.V[j].custo = g.E[i][j].peso + g.V[i].custo;
    g.V[j].ant = i;
  }
  return g;
}

Grafo bellman_ford(Grafo g, int s) {
  int i, j;
  int ant;
  int max = 0;
  i = s;

  while (max < MAX_VERTICES * 4) {
    for (j = 0; j < MAX_VERTICES; j++) {
      if (g.E[i][j].peso < INF && i != j) {
        g = relaxa(g, i, j);
      }
    }
    if (i == MAX_VERTICES - 1) {
      i = 0;
    } else {
      i++;
    }
    max++;
  }
  return g;
}

Grafo inicializa(Grafo g) {
  int i, j;

  // Nomes dos Vertices
  strcpy(g.V[0].nome, "Roteador");
  strcpy(g.V[1].nome, "Switch 1");
  strcpy(g.V[2].nome, "Switch 2");
  strcpy(g.V[3].nome, "Switch 3");
  strcpy(g.V[4].nome, "Estacao 1");
  strcpy(g.V[5].nome, "Estacao 2");
  strcpy(g.V[6].nome, "Estacao 3");
  strcpy(g.V[7].nome, "Estacao 4");

  // Inicializa a diagonal com 0 e todos os Pesos com INFINITO
  for (i = 0; i < MAX_VERTICES; i++) {
    for (j = 0; j < MAX_VERTICES; j++) {
      if (i == j) {
        g.E[i][j].peso = 0;
      } else {
        g.E[i][j].peso = INF;
      }
    }
  }

  g.E[0][1].peso = 8;
  g.E[1][0].peso = 8;

  g.E[0][2].peso = 9;
  g.E[2][0].peso = 9;

  g.E[1][2].peso = 3;
  g.E[2][1].peso = 3;

  g.E[1][3].peso = 2;
  g.E[3][1].peso = 2;

  g.E[1][4].peso = 7;
  g.E[4][1].peso = 7;

  g.E[1][5].peso = 3;
  g.E[5][1].peso = 3;

  g.E[2][3].peso = 2;
  g.E[3][2].peso = 2;

  g.E[2][6].peso = 1;
  g.E[6][2].peso = 1;

  g.E[2][7].peso = 3;
  g.E[7][2].peso = 3;

  g.E[3][6].peso = 4;
  g.E[6][3].peso = 4;

  g.E[4][5].peso = 2;
  g.E[5][4].peso = 2;

  g.E[6][7].peso = 2;
  g.E[7][6].peso = 2;

  return g;
}

Grafo ini(Grafo g, int s) {
  int i;

  for (i = 0; i < MAX_VERTICES; i++) {
    if (i == s) {
      g.V[i].custo = 0;
    } else {
      g.V[i].custo = INF;
    }

    g.V[i].ant = s;
  }

  return g;
}

void printCaminho(Grafo g) {
  int i, est = 4, atual;
  printf(
      "---------------------------------------------------------------------"
      "\n");
  printf(
      "|                           BELLMAN-FORD                            "
      "|\n");
  printf(
      "---------------------------------------------------------------------"
      "\n");

  for (i = 4; i < 8; i++) {
    printf("%s <- ", g.V[i].nome);
    atual = g.V[i].ant;
    while (atual != 0) {
      printf("%s <- ", g.V[atual].nome);
      atual = g.V[atual].ant;
    }
    printf(" %s. ", g.V[atual].nome);
    printf("Custo total: %d \n", g.V[i].custo);
  }
}

main() {
  int s, i, cont;
  Grafo g;
  g = inicializa(g);

inicio:
  printf(
      "---------------------------------------------------------------------"
      "\n");
  printf(
      "|                           BELLMAN-FORD                            "
      "|\n");
  printf(
      "---------------------------------------------------------------------"
      "\n");
  printf(
      "|   O algoritmo de Bellman-Ford resolve o problema do caminho mais  "
      "|\n");
  printf(
      "|curto de unica origem para o caso mais geral, o qual os pesos das  "
      "|\n");
  printf(
      "|arestas podem ser negativos.                                       "
      "|\n");
  printf(
      "---------------------------------------------------------------------"
      "\n\n");

  system("pause");
  system("cls");

  printf(
      "---------------------------------------------------------------------"
      "\n");
  printf(
      "|                           BELLMAN-FORD                            "
      "|\n");
  printf(
      "---------------------------------------------------------------------"
      "\n");
  printf("Escolha uma op��o.\n");
  printf("1. Caso teste.\n");
  printf("1. Escolha de onde quer sair.\n");
  printf("Valor: ");

  scanf("%d", &cont);
  system("cls");

  if (cont == 1) {
    g = ini(g, 0);
    g = bellman_ford(g, 0);
    printCaminho(g);
  } else {
    printf("Entre com o valor correspondente de onde deseja sair.\n");
    printf("0. Roteador.\n");
    printf("1. Switch 1.\n");
    printf("2. Switch 2.\n");
    printf("3. Switch 3.\n");
    printf("4. Estacao 1.\n");
    printf("5. Estacao 2.\n");
    printf("6. Estacao 3.\n");
    printf("7. Estacao 4.\n");
    printf("Valor: ");

    scanf("%d", &s);

    system("cls");

    g = ini(g, s);

    g = bellman_ford(g, s);

    printCaminho(g);
  }

  /*for(i=0; i < MAX_VERTICES; i++){
      printf("%s custo : %d \n", g.V[i].nome, g.V[i].custo);
  }*/

  // printf("\n");
}
