## Listas Encadeadas

Uma lista encadeada é uma estrutura linear dinâmica: uma coleção de nós em que cada nó guarda um dado e uma referência (link) para o próximo nó. Os nós não ficam em posições contíguas de memória, e a lista pode crescer ou encolher durante a execução.

```c
struct Node {
    int data;
    struct Node* next;
};
```

Tipos de lista encadeada:

- **Singly (simplesmente encadeada)**: cada nó aponta só para o próximo; percurso em uma direção.
- **Doubly (duplamente encadeada)**: cada nó guarda ponteiro para o próximo e para o anterior; percurso nos dois sentidos.
- **Circular**: o último nó aponta de volta para o primeiro (pode ser simples ou dupla).

| Operação                   | Array           | Lista Simples                 | Lista Dupla   |
| -------------------------- | --------------- | ----------------------------- | ------------- |
| Acesso/Busca               | O(1) / O(n)     | O(n)                          | O(n)          |
| Inserção no início         | O(n)            | O(1)                          | O(1)          |
| Inserção no fim            | O(1) amortizado | O(n) sem tail / O(1) com tail | O(1) com tail |
| Remoção (nó já encontrado) | O(n)            | O(1)\*                        | O(1)          |

\*Para remoção no início da lista simples; remoção arbitrária exige encontrar o nó anterior, O(n).

Algoritmos importantes sobre listas encadeadas, quase todos construídos sobre a técnica de **ponteiros lento e rápido (Fast & Slow Pointers / Floyd's Tortoise and Hare)**, que usa dois ponteiros avançando em velocidades diferentes para resolver problemas em O(n) de tempo e O(1) de espaço:

- **Reversão iterativa**: usa três ponteiros (`prev`, `cur`, `next`) para inverter os links um a um.
- **Encontrar o meio**: `slow` avança 1 passo, `fast` avança 2; quando `fast` chega ao fim, `slow` está no meio.
- **N-ésimo nó a partir do fim**: avança `fast` `n` passos à frente, depois move os dois juntos até `fast` chegar ao fim.
- **Detecção de ciclo**: se `slow` e `fast` se encontram, existe um ciclo.

```java
boolean hasCycle(Node head) {
    Node slow = head, fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) return true;
    }
    return false;
}
```

Implementação neste repositório: `c/lista.c`, `java/src/main/java/com/datastructures/linkedList/` (lista simples), `java/src/main/java/com/datastructures/doublyLinkedList/` (lista dupla) e `java/src/main/java/com/datastructures/circularList/` (lista circular).
