## Bellman-Ford em rede

### Conceito

Este exemplo tambem usa **Bellman-Ford**, mas com um grafo fixo que representa uma pequena rede com roteador, switches e estacoes.

O objetivo e calcular o menor caminho entre a origem escolhida e as estacoes.

### Implementacao no contexto deste repositorio

Em `bellman-ford.c`, o grafo e definido por:

```c
typedef struct grafo {
  Vertice vertices[MAX_VERTICES];
  Aresta arestas[MAX_VERTICES][MAX_VERTICES];
} Grafo;
```

Cada vertice guarda nome, custo acumulado e antecessor. Cada aresta guarda peso.

As funcoes principais sao:

- `inicializar_grafo`: monta o grafo da rede.
- `inicializar_custos`: define custo inicial e predecessor.
- `relaxar_aresta`: tenta melhorar uma distancia.
- `executar_bellman_ford`: aplica relaxamentos repetidos.
- `imprimir_caminhos`: mostra os caminhos encontrados.

### Ideia do algoritmo

1. Define todas as distancias como infinito.
2. Define a origem com custo zero.
3. Relaxa as arestas varias vezes.
4. Usa o predecessor de cada vertice para imprimir o caminho final.

### Por que isso e importante para iniciantes

Esse arquivo mostra uma aplicacao mais concreta de caminhos minimos: decidir rotas em uma rede. Ele tambem reforca a relacao entre grafos e problemas de infraestrutura.
