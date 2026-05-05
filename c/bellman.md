## Bellman-Ford

### Conceito

O **Bellman-Ford** encontra caminhos minimos a partir de uma origem em um grafo com pesos.

Ao contrario de Dijkstra, ele tambem pode lidar com arestas de peso negativo, desde que nao exista ciclo negativo alcancavel pela origem.

### Bellman-Ford no contexto deste repositorio

Em `bellman.c`, o usuario informa:

- numero de vertices;
- numero de arcos;
- origem, destino e peso de cada arco.

O grafo e guardado em uma matriz:

```c
int grafo[BUF][BUF][2];
```

O vetor `distancias` guarda as distancias, e `predecessores` guarda os predecessores usados para reconstruir o caminho.

### Ideia do algoritmo

1. Inicializa todas as distancias como infinito.
2. Define a distancia da origem como zero.
3. Relaxa todas as arestas `V - 1` vezes.
4. Faz uma passada final para detectar ciclo negativo.
5. Reconstrui o caminho usando os predecessores.

### Complexidade

- Tempo: `O(V * E)`.
- Memoria: depende da representacao do grafo.

### Por que isso e importante para iniciantes

Bellman-Ford e uma boa introducao ao conceito de relaxamento de arestas e aos cuidados necessarios quando pesos negativos existem.
