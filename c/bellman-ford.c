#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 8
#define INF 99999

typedef struct vertice {
  char nome[15];
  int custo;
  int antecessor;
} Vertice;

typedef struct aresta {
  int peso;
} Aresta;

typedef struct grafo {
  Vertice vertices[MAX_VERTICES];
  Aresta arestas[MAX_VERTICES][MAX_VERTICES];
} Grafo;

static Grafo relaxar_aresta(Grafo grafo, int origem, int destino) {
  if (grafo.arestas[origem][destino].peso + grafo.vertices[origem].custo <
      grafo.vertices[destino].custo) {
    grafo.vertices[destino].custo =
        grafo.arestas[origem][destino].peso + grafo.vertices[origem].custo;
    grafo.vertices[destino].antecessor = origem;
  }
  return grafo;
}

static Grafo executar_bellman_ford(Grafo grafo, int origem) {
  int vertice_atual = origem;
  int destino;
  int iteracoes = 0;

  while (iteracoes < MAX_VERTICES * 4) {
    for (destino = 0; destino < MAX_VERTICES; destino++) {
      if (grafo.arestas[vertice_atual][destino].peso < INF &&
          vertice_atual != destino) {
        grafo = relaxar_aresta(grafo, vertice_atual, destino);
      }
    }

    if (vertice_atual == MAX_VERTICES - 1) {
      vertice_atual = 0;
    } else {
      vertice_atual++;
    }

    iteracoes++;
  }

  return grafo;
}

static Grafo inicializar_grafo(Grafo grafo) {
  int origem;
  int destino;

  strcpy(grafo.vertices[0].nome, "Roteador");
  strcpy(grafo.vertices[1].nome, "Switch 1");
  strcpy(grafo.vertices[2].nome, "Switch 2");
  strcpy(grafo.vertices[3].nome, "Switch 3");
  strcpy(grafo.vertices[4].nome, "Estacao 1");
  strcpy(grafo.vertices[5].nome, "Estacao 2");
  strcpy(grafo.vertices[6].nome, "Estacao 3");
  strcpy(grafo.vertices[7].nome, "Estacao 4");

  for (origem = 0; origem < MAX_VERTICES; origem++) {
    for (destino = 0; destino < MAX_VERTICES; destino++) {
      grafo.arestas[origem][destino].peso = origem == destino ? 0 : INF;
    }
  }

  grafo.arestas[0][1].peso = 8;
  grafo.arestas[1][0].peso = 8;
  grafo.arestas[0][2].peso = 9;
  grafo.arestas[2][0].peso = 9;
  grafo.arestas[1][2].peso = 3;
  grafo.arestas[2][1].peso = 3;
  grafo.arestas[1][3].peso = 2;
  grafo.arestas[3][1].peso = 2;
  grafo.arestas[1][4].peso = 7;
  grafo.arestas[4][1].peso = 7;
  grafo.arestas[1][5].peso = 3;
  grafo.arestas[5][1].peso = 3;
  grafo.arestas[2][3].peso = 2;
  grafo.arestas[3][2].peso = 2;
  grafo.arestas[2][6].peso = 1;
  grafo.arestas[6][2].peso = 1;
  grafo.arestas[2][7].peso = 3;
  grafo.arestas[7][2].peso = 3;
  grafo.arestas[3][6].peso = 4;
  grafo.arestas[6][3].peso = 4;
  grafo.arestas[4][5].peso = 2;
  grafo.arestas[5][4].peso = 2;
  grafo.arestas[6][7].peso = 2;
  grafo.arestas[7][6].peso = 2;

  return grafo;
}

static Grafo inicializar_custos(Grafo grafo, int origem) {
  int indice_vertice;

  for (indice_vertice = 0; indice_vertice < MAX_VERTICES; indice_vertice++) {
    grafo.vertices[indice_vertice].custo =
        indice_vertice == origem ? 0 : INF;
    grafo.vertices[indice_vertice].antecessor = origem;
  }

  return grafo;
}

static void imprimir_caminhos(Grafo grafo) {
  int indice_vertice;
  int vertice_atual;

  printf(
      "---------------------------------------------------------------------"
      "\n");
  printf(
      "|                           BELLMAN-FORD                            "
      "|\n");
  printf(
      "---------------------------------------------------------------------"
      "\n");

  for (indice_vertice = 4; indice_vertice < 8; indice_vertice++) {
    printf("%s <- ", grafo.vertices[indice_vertice].nome);
    vertice_atual = grafo.vertices[indice_vertice].antecessor;
    while (vertice_atual != 0) {
      printf("%s <- ", grafo.vertices[vertice_atual].nome);
      vertice_atual = grafo.vertices[vertice_atual].antecessor;
    }
    printf(" %s. ", grafo.vertices[vertice_atual].nome);
    printf("Custo total: %d \n", grafo.vertices[indice_vertice].custo);
  }
}

int main(void) {
  int origem;
  int opcao;
  Grafo grafo = inicializar_grafo(grafo);

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
  printf("Escolha uma opcao.\n");
  printf("1. Caso teste.\n");
  printf("2. Escolha de onde quer sair.\n");
  printf("Valor: ");

  scanf("%d", &opcao);
  system("cls");

  if (opcao == 1) {
    grafo = inicializar_custos(grafo, 0);
    grafo = executar_bellman_ford(grafo, 0);
    imprimir_caminhos(grafo);
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

    scanf("%d", &origem);
    system("cls");

    grafo = inicializar_custos(grafo, origem);
    grafo = executar_bellman_ford(grafo, origem);
    imprimir_caminhos(grafo);
  }

  return 0;
}
