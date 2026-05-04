# Árvore Binária de Busca (`BinarySearchTree<T>`)

## Conceito

Uma **Árvore Binária de Busca** (BST - Binary Search Tree) é uma estrutura hierárquica onde cada nó tem no máximo dois
filhos, respeitando a seguinte invariante:

> Todo nó na subárvore **esquerda** tem valor **menor** que o nó atual.
> Todo nó na subárvore **direita** tem valor **maior ou igual** que o nó atual.

```
Inserindo: 13, 10, 25, 2, 12, 20, 31, 29, 32

           13
          /  \
        10    25
       /  \  /  \
      2   12 20  31
               /   \
              29   32
```

Essa propriedade permite busca eficiente: a cada nó visitado, metade da árvore é descartada.

### Complexidade

| Operação   | Caso médio | Pior caso (degenerado) |
| ---------- | ---------- | ---------------------- |
| `insert()` | O(log n)   | O(n)                   |
| `remove()` | O(log n)   | O(n)                   |
| Busca      | O(log n)   | O(n)                   |

O pior caso ocorre quando os elementos são inseridos em ordem crescente ou decrescente, criando uma lista encadeada.
Árvores balanceadas (AVL, Red-Black) evitam esse problema.

### Percursos

Três formas de percorrer todos os nós:

| Percurso     | Ordem de visita  | Resultado para a árvore acima         |
| ------------ | ---------------- | ------------------------------------- |
| **InOrdem**  | esq - raiz - dir | 2 10 12 13 20 25 29 31 32 (crescente) |
| **PreOrdem** | raiz - esq - dir | 13 10 2 12 25 20 31 29 32             |
| **PosOrdem** | esq - dir - raiz | 2 12 10 20 29 32 31 25 13             |

InOrdem em uma BST sempre produz os elementos em ordem crescente.

### Remoção - três casos

1. **Nó folha** (sem filhos): basta remover o nó
2. **Nó com um filho**: substitui o nó pelo filho
3. **Nó com dois filhos**: encontra o **sucessor in-order** (menor nó da subárvore direita), copia seu valor para o nó
   atual e remove o sucessor

```java
// Implementação recursiva limpa:
private BinaryNode<T> remove(BinaryNode<T> current, T value) {
    if (current == null) return null;
    int cmp = value.compareTo(current.getValue());
    if (cmp < 0) current.setLeft(remove(current.getLeft(), value));
    else if (cmp > 0) current.setRight(remove(current.getRight(), value));
    else {
        if (current.getLeft() == null) return current.getRight(); // caso 1 e 2
        if (current.getRight() == null) return current.getLeft(); // caso 2
        BinaryNode<T> successor = minimum(current.getRight());    // caso 3
        current.setValue(successor.getValue());
        current.setRight(remove(current.getRight(), successor.getValue()));
    }
    return current;
}
```

## O que o exemplo faz

```java
BinarySearchTree<IntValue> tree = new BinarySearchTree<>();
// insere: 13, 10, 25, 2, 12, 20, 31, 29, 32

tree.printInOrder();  // 2 10 12 13 20 25 29 31 32
tree.printPreOrder(); // 13 10 2 12 25 20 31 29 32
tree.printPostOrder(); // 2 12 10 20 29 32 31 25 13

tree.remove(new IntValue(2));  // folha
tree.remove(new IntValue(31)); // nó com um filho (29 e 32)
tree.remove(new IntValue(13)); // raiz com dois filhos
```

`IntValue` encapsula um `Integer` e implementa `Comparable<IntValue>` via `Integer.compare()`.

## Como praticar

**Exercício 1 - busca**
Adicione um método `boolean contem(T value)` que percorre a árvore em O(log n) usando a propriedade BST (sem
percorrer tudo).

**Exercício 2 - altura**
Adicione `int altura()` que retorna a altura da árvore (maior número de arestas da raiz até uma folha). Use recursão:

```java
private int altura(BinaryNode<T> node) {
    if (node == null) return -1;
    return 1 + Math.max(altura(node.getLeft()), altura(node.getRight()));
}
```

**Exercício 3 - mínimo e máximo**
Adicione `T minimo()` e `T maximo()`. O mínimo é o nó mais à esquerda; o máximo, o mais à direita.

**Exercício 4 - percurso por nível (BFS)**
Implemente `printByLevel()` que imprime os nós nível a nível usando uma `Queue`:

```
Nível 0: 13
Nível 1: 10 25
Nível 2: 2 12 20 31
```

**Exercício 5 - verificar se é BST**
Dado um nó raiz, escreva `boolean ehBST()` que verifica se a árvore respeita a invariante BST. Inserções sempre mantêm a
propriedade, mas e se os nós forem criados manualmente?

**Exercício 6 - inserção com String**
A classe `String` já implementa `Comparable<String>`. Crie uma `BinarySearchTree<String>` diretamente (sem `IntValue`) e
insira
palavras. O percurso in-ordem deve produzir a lista em ordem alfabética.
