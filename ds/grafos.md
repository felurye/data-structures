## Grafos

Um grafo é uma estrutura de dados não linear formada por um conjunto de vértices (nós) e um conjunto de arestas que conectam pares de vértices. É usado para representar redes, relacionamentos e conexões em geral.

Terminologia: **vértice/nó** é um ponto do grafo; **aresta** é uma conexão entre dois vértices; **grau de um vértice** é o número de arestas incidentes nele; **caminho** é uma sequência de vértices conectados; **ciclo** é um caminho que começa e termina no mesmo vértice; **grafo conectado** tem caminho entre todo par de vértices.

Tipos de grafo: **não direcionado** (arestas sem sentido), **direcionado/dígrafo** (arestas com sentido, cada vértice tem grau de entrada/indegree e grau de saída/outdegree), **ponderado** (arestas com peso/custo) e **não ponderado**.

Representação:

- **Matriz de adjacência**: matriz `V x V` onde `matriz[i][j] = 1` indica aresta entre `i` e `j`. Espaço O(V²), boa para grafos densos. Para grafo não direcionado, a matriz é simétrica.
- **Lista de adjacência**: cada vértice guarda uma lista dos vértices adjacentes. Espaço O(V + E), boa para grafos esparsos.

Lema do aperto de mãos (handshaking lemma): em um grafo não direcionado, a soma dos graus de todos os vértices é igual a duas vezes o número de arestas (cada aresta contribui 1 para o grau de cada um dos seus dois extremos).

**Busca em largura (BFS)**: visita os vértices nível por nível, usando uma fila. Complexidade O(V + E).

```java
void bfs(int start, List<List<Integer>> adj) {
    boolean[] visited = new boolean[adj.size()];
    Queue<Integer> q = new ArrayDeque<>();
    q.offer(start);
    visited[start] = true;
    while (!q.isEmpty()) {
        int node = q.poll();
        visit(node);
        for (int next : adj.get(node)) {
            if (!visited[next]) { visited[next] = true; q.offer(next); }
        }
    }
}
```

**Busca em profundidade (DFS)**: vai o mais fundo possível antes de retroceder (backtrack), usando pilha ou recursão. Complexidade O(V + E).

| Aspecto                                  | BFS                                         | DFS                                                  |
| ---------------------------------------- | ------------------------------------------- | ---------------------------------------------------- |
| Estrutura                                | fila                                        | pilha / recursão                                     |
| Percurso                                 | nível por nível                             | em profundidade                                      |
| Caminho mais curto (grafo não ponderado) | encontra                                    | pode não encontrar                                   |
| Memória                                  | geralmente maior                            | geralmente menor                                     |
| Bom para                                 | caminho mais curto, menor número de arestas | ordenação topológica, detecção de ciclo, componentes |

**Detecção de ciclo**: em grafo não direcionado, se ao visitar com DFS encontramos um vértice já visitado que não é o pai do vértice atual, há um ciclo; em grafo direcionado, um ciclo existe se encontramos uma aresta de retorno (back edge) para um vértice que já está na pilha de recursão atual.

**Ordenação topológica** (apenas para DAG, grafo acíclico direcionado): ordena os vértices de forma que, para toda aresta `u -> v`, `u` venha antes de `v`. Implementada com DFS: faz DFS em todos os vértices, empilha cada vértice quando sua recursão termina, depois inverte a pilha para obter a ordem topológica.

Aplicações: redes sociais, GPS e mapas, estrutura de links entre páginas web, roteamento de redes, dependências e escalonamento de tarefas, e circuitos elétricos.

Dicas rápidas: use lista de adjacência para grafos esparsos e matriz de adjacência para grafos densos; sempre marque os vértices visitados em BFS/DFS para evitar loops infinitos; para caminho mínimo em grafo ponderado, use o algoritmo de Dijkstra (ou Bellman-Ford quando há arestas com peso negativo).

Implementação neste repositório: `c/grafo.c` (representação e percursos de grafo) e `c/bellman-ford.c`/`c/bellman.c` (algoritmo de Bellman-Ford para caminho mínimo com pesos negativos).
