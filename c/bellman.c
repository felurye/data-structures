#include <stdio.h>

#define DISTANCIA_INFINITA 1000
#define SEM_ANTECESSOR -1
#define VERDADEIRO 1
#define FALSO 0
#define MAX_VERTICES 100

static int grafo[MAX_VERTICES][MAX_VERTICES][2];
static int distancias[MAX_VERTICES];
static int predecessores[MAX_VERTICES];
static int quantidade_vertices;
static int quantidade_arestas;

static void inicializar_origem_unica(int origem);
static void relaxar_aresta(int origem, int destino);
static int executar_bellman_ford(int origem);
static void imprimir_caminho(int origem, int destino);

int main(void) {
  int indice_aresta;
  int origem_aresta;
  int destino_aresta;
  int contador;
  int origem;
  int destino;
  int peso;

  puts("\n numero de vertices que tera o grafo : ");
  scanf("%d", &quantidade_vertices);
  puts("\nnumero de arcos presente no grafo : ");
  scanf("%d", &quantidade_arestas);

  fprintf(stdout,
          "\nagora digite %d numero de arcos entre dois vertices \n junto com "
          "seus pesos \n",
          quantidade_arestas);

  for (indice_aresta = 0; indice_aresta < quantidade_arestas; indice_aresta++) {
    fprintf(stdout, "\npar com %d e com (U V W) : ", indice_aresta + 1);
    scanf("%d %d %d", &origem_aresta, &destino_aresta, &peso);
    origem_aresta--;
    destino_aresta--;
    grafo[origem_aresta][destino_aresta][0] = 1;
    grafo[origem_aresta][destino_aresta][1] = peso;
  }

  fprintf(stdout, "\no grafo tem %d vertices e %d arcos foram criados\n",
          quantidade_vertices, quantidade_arestas);

  puts("\n listando dados do grafo : \n");
  for (origem_aresta = 0; origem_aresta < quantidade_vertices; origem_aresta++) {
    contador = 1;
    fprintf(stdout, "\nanalisando %d  : \n", origem_aresta + 1);

    for (destino_aresta = 0; destino_aresta < quantidade_vertices;
         destino_aresta++) {
      if (grafo[origem_aresta][destino_aresta][0] == 1) {
        fprintf(stdout, "(%d) vertice = %d e peso = %d\n", contador,
                destino_aresta + 1, grafo[origem_aresta][destino_aresta][1]);
        contador++;
      }
    }
  }

  puts("\nprecine qualquer tecla para calcular o grafo\n");

  do {
    puts("\n digite numero do vertice: ");
    scanf("%d", &origem);
    contador = executar_bellman_ford(origem - 1);
    if (contador == VERDADEIRO) {
      puts("\nAqui fonte unica algoritmo Shortest Caminho e logicamente aplicavel\n");
    } else {
      puts(
          "\nAqui fonte unica algoritmo Shortest Caminho e logicamente nao "
          "aplicavel\n");
    }

    puts("\ndigite numero da aresta de destino : ");
    scanf("%d", &destino);

    fprintf(stdout,
            "\nmenor caminho da aresta (%d) para aresta (%d)  : \n\n", origem,
            destino);

    imprimir_caminho(origem - 1, destino - 1);
    fprintf(stdout, "\n\ne a distancia entre as duas arestas eh %d",
            distancias[destino - 1]);

    puts(
        "\n\ndigite 1 apra continuar calculando\n ou 2 para terminar "
        "calculo\n\n escolha um : ");

    scanf("%d", &contador);
  } while (contador != 2);

  puts("\ndigite uma tecla para terminar...");
  return 0;
}

static void inicializar_origem_unica(int origem) {
  int indice_vertice;

  for (indice_vertice = 0; indice_vertice < quantidade_vertices;
       indice_vertice++) {
    distancias[indice_vertice] = DISTANCIA_INFINITA;
    predecessores[indice_vertice] = SEM_ANTECESSOR;
  }
  distancias[origem] = 0;
}

static void relaxar_aresta(int origem, int destino) {
  if (distancias[destino] > (distancias[origem] + grafo[origem][destino][1])) {
    distancias[destino] = distancias[origem] + grafo[origem][destino][1];
    predecessores[destino] = origem;
  }
}

static int executar_bellman_ford(int origem) {
  int iteracao;
  int vertice_origem;
  int vertice_destino;

  inicializar_origem_unica(origem);
  for (iteracao = 0; iteracao < (quantidade_vertices - 1); iteracao++) {
    for (vertice_origem = 0; vertice_origem < quantidade_vertices;
         vertice_origem++) {
      for (vertice_destino = 0; vertice_destino < quantidade_vertices;
           vertice_destino++) {
        if (grafo[vertice_origem][vertice_destino][0] == 1) {
          relaxar_aresta(vertice_origem, vertice_destino);
        }
      }
    }
  }

  for (vertice_origem = 0; vertice_origem < quantidade_vertices;
       vertice_origem++) {
    for (vertice_destino = 0; vertice_destino < quantidade_vertices;
         vertice_destino++) {
      if (grafo[vertice_origem][vertice_destino][0] == 1) {
        if (distancias[vertice_destino] >
            (distancias[vertice_origem] + grafo[vertice_origem][vertice_destino][1])) {
          return FALSO;
        }
      }
    }
  }

  return VERDADEIRO;
}

static void imprimir_caminho(int origem, int destino) {
  if (destino == origem) {
    printf("  %d  ", origem + 1);
  } else if (predecessores[destino] == SEM_ANTECESSOR) {
    fprintf(stdout, "nao tem caminho %d a %d ", origem + 1, destino + 1);
  } else {
    imprimir_caminho(origem, predecessores[destino]);
    fprintf(stdout, "  %d  ", destino + 1);
  }
}
