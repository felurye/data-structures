## Grafo

### Conceito

Um **grafo** representa relacoes entre elementos.

Os elementos sao chamados de vertices, e as ligacoes entre eles sao chamadas de arestas.

- **Vertice**: um ponto do grafo.
- **Aresta**: uma ligacao entre dois vertices.
- **Adjacencia**: indica que um vertice esta ligado a outro.
- **Matriz de adjacencia**: usa uma matriz para registrar quais vertices se conectam.

### Grafo no contexto deste repositorio

Em `grafo.c`, o grafo tem cinco vertices fixos:

```c
#define MAX_VERTICES 5
```

Cada vertice tem um nome, e a matriz `arestas` indica se existe uma ligacao entre dois vertices:

```c
struct grafo {
  struct vertice vertices[MAX_VERTICES];
  struct aresta arestas[MAX_VERTICES][MAX_VERTICES];
};
```

Quando `adjacente == 1`, existe adjacencia. Quando `adjacente == 0`, nao existe.

### Ideia do algoritmo

1. Define os nomes dos vertices.
2. Preenche manualmente a matriz de adjacencia.
3. Percorre todas as posicoes da matriz.
4. Imprime cada relacao encontrada.

### Por que isso e importante para iniciantes

Grafos modelam redes, rotas, dependencias, amizades, mapas e conexoes de computadores. A matriz de adjacencia e uma das representacoes mais diretas para comecar.
