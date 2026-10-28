## Árvore Binária de Busca (BST)

Uma BST é uma árvore binária em que, para todo nó `N`: todas as chaves na subárvore esquerda são menores que `N` e todas as chaves na subárvore direita são maiores que `N`. Ambas as subárvores também precisam ser BSTs, e por padrão não há chaves duplicadas. O percurso em ordem (inorder) de uma BST sempre gera os elementos em ordem crescente - é por isso que ela é a base de muitas estruturas mais avançadas.

```java
Node search(Node root, int key) {
    while (root != null) {
        if (key == root.data) return root;
        root = key < root.data ? root.left : root.right;
    }
    return null;
}

Node insert(Node root, int key) {
    if (root == null) return new Node(key);
    if (key < root.data) root.left = insert(root.left, key);
    else if (key > root.data) root.right = insert(root.right, key);
    return root;
}
```

Busca, inserção e remoção custam O(h), onde `h` é a altura da árvore: O(log n) no caso médio (árvore balanceada) e O(n) no pior caso (árvore degenerada/enviesada). A remoção tem três casos: nó folha (remove direto), nó com um filho (substitui pelo filho) e nó com dois filhos (substitui pelo sucessor em ordem - o menor valor da subárvore direita - ou pelo predecessor em ordem - o maior valor da subárvore esquerda - e remove esse nó recursivamente).

Uma **BST balanceada** garante operações O(log n); exemplos de árvores que se auto-balanceiam são a árvore AVL e a árvore red-black, usadas quando é preciso garantir desempenho previsível mesmo com inserções e remoções adversárias.

Aplicações: busca eficiente, manter dados ordenados, implementar sets e maps ordenados, consultas de intervalo (range queries), indexação de bancos de dados e base para árvores mais avançadas (AVL, red-black, splay).

Implementação neste repositório: `c/arvore-binaria.c` (BST básica), `c/arvore-avl.c` (BST auto-balanceada por rotações, garante O(log n) mesmo no pior caso) e `c/arvore-red-black.c` (BST auto-balanceada por coloração de nós, outra forma de garantir O(log n)).
