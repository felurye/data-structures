## Arrays

Um array é uma coleção de elementos do mesmo tipo, acessados por índice (0-based), armazenados em memória contígua.

```java
int[] a = {10, 20, 30, 40};   // declaração e inicialização com valores
int[] b = new int[5];          // declaração com tamanho (valores padrão 0)
```

| Operação                          | Complexidade    |
| --------------------------------- | --------------- |
| Acesso (`a[i]`)                   | O(1)            |
| Busca (por valor)                 | O(n)            |
| Inserção no final                 | O(1) amortizado |
| Inserção no meio (em uma posição) | O(n)            |
| Remoção no meio (de uma posição)  | O(n)            |

Inserção em uma posição desloca os elementos seguintes uma casa à direita; remoção desloca os elementos seguintes uma casa à esquerda. Arrays usam memória contígua, e em Java e C o tamanho é fixo após a criação (para tamanho dinâmico, usa-se `ArrayList` em Java ou realocação manual com `realloc()` em C).

Implementação neste repositório: `c/lista.c` e `java/src/main/java/com/datastructures/list/` trabalham com coleções sequenciais de elementos.
