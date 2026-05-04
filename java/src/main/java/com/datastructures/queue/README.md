# Fila Java (`Queue`)

## Conceito

`Queue<T>` é uma interface do Java que define o comportamento **FIFO** (First In, First Out): o primeiro elemento
inserido é o primeiro a sair - como uma fila de espera.

```
enqueue: Ford --> [Ford]
enqueue: Chevrolet --> [Ford, Chevrolet]
enqueue: Fiat --> [Ford, Chevrolet, Fiat]
dequeue --> Ford | [Chevrolet, Fiat]
```

A implementação mais comum é `LinkedList`, que internamente usa uma lista duplamente encadeada.

### Dois grupos de métodos

`Queue` oferece dois sabores para cada operação - um que lança exceção e um que retorna um valor especial:

| Operação       | Lança exceção | Retorna valor especial |
| -------------- | ------------- | ---------------------- |
| Inserir        | `add(T)`      | `offer(T)` → `false`   |
| Remover        | `remove()`    | `poll()` → `null`      |
| Consultar topo | `element()`   | `peek()` → `null`      |

Prefira os métodos com retorno especial (`offer`, `poll`, `peek`) para evitar exceções em filas com limite de capacidade
ou vazias.

### Casos de uso reais

- Processamento de tarefas em ordem de chegada
- Fila de impressão
- BFS (busca em largura) em grafos e árvores
- Sistemas de mensagens (produtor/consumidor)

## O que o exemplo faz

```java
Queue<Car> queue = new LinkedList<>();

queue.add(new Car("Ford"));
queue.add(new Car("Chevrolet"));
queue.add(new Car("Fiat"));
queue.offer(new Car("Peugeot"));       // igual a add para LinkedList

System.out.println(queue);             // [Ford, Chevrolet, Fiat, Peugeot]
System.out.println(queue.element());   // Ford (não remove)
System.out.println(queue.peek());      // Ford (não remove, null se vazia)

System.out.println(queue.remove());    // Ford (remove, lança exceção se vazia)
System.out.println(queue.poll());      // Chevrolet (remove, null se vazia)
System.out.println(queue);             // [Fiat, Peugeot]

System.out.println(queue.isEmpty());   // false
```

## Como praticar

**Exercício 1 - simulação de fila**
Simule uma fila de atendimento: adicione 5 clientes, atenda-os um a um com `poll()` e imprima a ordem de atendimento.

**Exercício 2 - BFS em árvore**
Dado o nó raiz de uma `BinarySearchTree`, implemente uma busca em largura (BFS) usando uma `Queue` para percorrer a
árvore
nível por nível.

**Exercício 3 - PriorityQueue**
Explore `PriorityQueue<Car>` onde carros com marcas menores (alfabeticamente) têm prioridade. Adicione carros em ordem
aleatória e remova-os - qual é a ordem de saída?

```java
Queue<Car> pq = new PriorityQueue<>(Comparator.comparing(Car::getBrand));
```

**Exercício 4 - fila com limite**
`ArrayDeque` é uma alternativa a `LinkedList` para filas. Implemente uma fila com capacidade máxima de 3 elementos: se
cheia, `offer()` retorna `false` sem adicionar.

**Exercício 5 - produtor/consumidor**
Modele um sistema simples: um produtor adiciona números de 1 a 10 em uma `Queue<Integer>`, e um consumidor os processa (
imprime o dobro) um a um.
