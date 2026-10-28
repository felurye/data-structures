## Fila (Queue) e Deque

Uma fila é uma estrutura linear que segue a ordem **FIFO** (First In, First Out). Inserção acontece no final (rear) e remoção no início (front) - como uma fila de banco.

| Operação                  | Descrição                                | Complexidade |
| ------------------------- | ---------------------------------------- | ------------ |
| `enqueue(x)` / `offer(x)` | insere `x` no final                      | O(1)         |
| `dequeue()` / `poll()`    | remove e retorna o elemento da frente    | O(1)         |
| `peek()`                  | retorna o elemento da frente sem remover | O(1)         |

```java
Queue<Integer> q = new ArrayDeque<>();
q.offer(10);
q.offer(20);
int front = q.peek(); // 10
int x = q.poll();     // 10, remove
```

Tipos de fila: **simples** (FIFO padrão), **circular** (a última posição se conecta de volta à primeira, melhor uso de espaço em implementação com array), **de prioridade** (os elementos são removidos por prioridade, não por ordem de chegada) e **deque** (double-ended queue, permite inserção e remoção nas duas pontas, podendo se comportar tanto como fila quanto como pilha).

```java
Deque<Integer> dq = new ArrayDeque<>();
dq.addFirst(10);
dq.addLast(20);
dq.removeFirst();
dq.removeLast();
```

Todas as operações de `Deque` (addFirst, addLast, removeFirst, removeLast, peekFirst, peekLast) são O(1).

Aplicações: escalonamento de CPU (round-robin), spooling de impressão, busca em largura (BFS) em grafos, atendimento de requisições em servidores web, simulação de filas da vida real e janela deslizante máxima/mínima (geralmente resolvida com deque).

Implementação neste repositório: `c/fila.c`, `java/src/main/java/com/datastructures/queue/` e `java/src/main/java/com/datastructures/linkedQueue/`.
