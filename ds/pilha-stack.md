## Pilha (Stack)

Uma pilha é uma estrutura linear que segue a ordem **LIFO** (Last In, First Out - o último elemento inserido é o primeiro removido). Inserção e remoção acontecem apenas em uma extremidade, chamada topo (top).

| Operação           | Descrição                              | Complexidade |
| ------------------ | -------------------------------------- | ------------ |
| `push(x)`          | adiciona `x` no topo                   | O(1)         |
| `pop()`            | remove e retorna o elemento do topo    | O(1)         |
| `peek()` / `top()` | retorna o elemento do topo sem remover | O(1)         |
| `isEmpty()`        | verifica se está vazia                 | O(1)         |

Pode ser implementada com array (mais simples, mas com tamanho fixo e risco de overflow) ou com lista encadeada (tamanho dinâmico). Em Java, a recomendação é usar `Deque` (`ArrayDeque`) em vez da classe legada `Stack`:

```java
Deque<Integer> st = new ArrayDeque<>();
st.push(10);
st.push(20);
int x = st.peek();  // 20
int y = st.pop();   // 20
```

Aplicações: gerenciamento de chamadas de função (call stack), avaliação de expressões (infixa, prefixa, pós-fixa), checagem de parênteses balanceados, desfazer/refazer (undo/redo) em editores, busca em profundidade (DFS) e histórico de navegação (botão voltar).

Padrões importantes com pilha:

- **Parênteses balanceados**: empilha abertura de parêntese; ao encontrar um fechamento, a pilha não pode estar vazia e o topo precisa casar com o tipo de abertura correspondente; no final, a pilha precisa estar vazia.
- **Próximo maior elemento (Next Greater Element)**: percorre da direita para a esquerda mantendo uma pilha decrescente, removendo elementos menores ou iguais ao atual antes de empilhar.
- **Pilha monotônica**: mantém os elementos em ordem (crescente ou decrescente); cada elemento é empilhado e desempilhado no máximo uma vez, dando complexidade total O(n). Útil para problemas de "próximo maior/menor elemento" e span de preços em bolsa (stock span).

Implementação neste repositório: `c/pilha.c`, `java/src/main/java/com/datastructures/stack/` e `java/src/main/java/com/datastructures/linkedStack/`. Veja também [c/pilha.md](../c/pilha.md), que explica o uso de pilha para validar parênteses balanceados no código deste repositório.
