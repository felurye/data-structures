# Lista Duplamente Encadeada (`DoublyLinkedList<T>`)

## Conceito

Uma **lista duplamente encadeada** é como a lista simplesmente encadeada, mas cada nó conhece tanto o **próximo** quanto
o **anterior**. Isso permite navegação nos dois sentidos.

```
null <--> [A] <--> [B] <--> [C] <--> [D] <--> null
          ^                           ^
        head                        tail
```

### Comparação com lista simples

|                        | Lista simples              | Lista dupla             |
| ---------------------- | -------------------------- | ----------------------- |
| Memória por nó         | `value + next`             | `value + next + prev`   |
| Percurso               | Apenas para frente         | Para frente e para trás |
| Remoção por referência | O(n) - precisa do anterior | O(1) - nó já tem `prev` |
| Inserção no final      | O(n)                       | O(1) - usa `tail`       |

A lista dupla mantém dois ponteiros: `head` e `tail`. Isso torna inserção no final O(1) (sem percorrer a lista
toda).

### Nó duplo

```java
public class DoubleNode<T> {
    private T value;
    private DoubleNode<T> next;
    private DoubleNode<T> prev;
}
```

## O que o exemplo faz

```java
DoublyLinkedList<String> list = new DoublyLinkedList<>();

list.add("A"); list.add("B"); list.add("C");
list.add("D"); list.add("E");

System.out.println("normal:  " + list);
// null<-->[A]<-->[B]<-->[C]<-->[D]<-->[E]<-->null

System.out.println("reverse:  " + list.toStringReverse());
// null<-->[E]<-->[D]<-->[C]<-->[B]<-->[A]<-->null

list.remove(2);
// remove C: null<-->[A]<-->[B]<-->[D]<-->[E]<-->null

list.add(2, "X");
// insere X no índice 2: null<-->[A]<-->[B]<-->[X]<-->[D]<-->[E]<-->null

System.out.println("get(2): " + list.get(2)); // X
System.out.println("size: " + list.size());   // 5
```

`toStringReverse()` percorre de `tail` até `head` usando `getPrev()`, demonstrando a navegação
bidirecional.

## Como praticar

**Exercício 1 - addFirst e addLast**
Adicione métodos `addFirst(T)` e `addLast(T)` explícitos (ambos O(1)). `addLast` já é o comportamento de `add(T)`.

**Exercício 2 - removeFirst e removeLast**
Adicione `T removeFirst()` e `T removeLast()`, ambos O(1) graças aos ponteiros `head` e `tail`.

**Exercício 3 - busca bidirecional**
Dado um índice, implemente `getNode` de forma otimizada: se o índice for menor que `size/2`, percorra a partir do
início; caso contrário, percorra a partir do fim.

**Exercício 4 - LinkedList do Java**
`java.util.LinkedList` é uma lista duplamente encadeada. Explore seus métodos `addFirst`, `addLast`, `removeFirst`,
`removeLast`, `peekFirst`, `peekLast`. Como se comparam com esta implementação?

**Exercício 5 - implementar um deque**
Um **deque** (double-ended queue) permite inserção e remoção em ambas as extremidades. Usando a lista dupla, implemente
as operações `pushFront`, `pushBack`, `popFront`, `popBack`.

**Exercício 6 - ordenação por inserção**
Implemente o **insertion sort** usando a lista dupla: para cada elemento novo, encontre a posição correta percorrendo a
lista e insira-o lá usando `add(int, T)`.
