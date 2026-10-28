## Árvores Binárias

Uma árvore binária é uma estrutura hierárquica em que cada nó tem no máximo dois filhos (esquerdo e direito), e o nó do topo é a raiz (root).

```java
class TreeNode {
    int data;
    TreeNode left, right;
}
```

Terminologia: **raiz** é o nó do topo; **pai/filho** descrevem a relação de conexão; **folha** é um nó sem filhos; **altura de um nó** é o número de arestas no caminho mais longo até uma folha; **altura da árvore** é a altura da raiz.

Tipos de árvore binária: **cheia (full)** - todo nó tem 0 ou 2 filhos; **completa (complete)** - todos os níveis preenchidos, exceto possivelmente o último, preenchido da esquerda para a direita; **perfeita (perfect)** - todos os nós internos têm 2 filhos e todas as folhas estão no mesmo nível; **balanceada** - para cada nó, a diferença de altura entre as subárvores esquerda e direita é no máximo 1; **degenerada/enviesada (skewed)** - cada nó tem apenas um filho (equivalente a uma lista encadeada).

Os três percursos em profundidade (DFS) e o percurso em largura:

| Percurso                     | Ordem                   | Uso típico                                     |
| ---------------------------- | ----------------------- | ---------------------------------------------- |
| Pré-ordem (preorder)         | Raiz, Esquerda, Direita | copiar/serializar a árvore                     |
| Em ordem (inorder)           | Esquerda, Raiz, Direita | em uma BST, dá os elementos em ordem crescente |
| Pós-ordem (postorder)        | Esquerda, Direita, Raiz | deletar a árvore, avaliar expressões           |
| Em nível (level order / BFS) | nível por nível         | usa fila                                       |

```java
void inorder(TreeNode root) {
    if (root == null) return;
    inorder(root.left);
    visit(root);
    inorder(root.right);
}

void levelOrder(TreeNode root) {
    if (root == null) return;
    Queue<TreeNode> q = new ArrayDeque<>();
    q.offer(root);
    while (!q.isEmpty()) {
        TreeNode n = q.poll();
        visit(n);
        if (n.left != null) q.offer(n.left);
        if (n.right != null) q.offer(n.right);
    }
}
```

Problemas clássicos sobre árvore binária, todos resolvidos recursivamente em O(n) de tempo e O(h) de espaço (onde `h` é a altura da árvore, usada na pilha de recursão):

- **Altura**: `1 + max(altura(esquerda), altura(direita))`, com altura de árvore vazia = -1 (ou 0, dependendo da convenção).
- **Tamanho (número de nós)**: `1 + tamanho(esquerda) + tamanho(direita)`.
- **Diâmetro**: o caminho mais longo entre quaisquer dois nós (medido em arestas); em cada nó, o diâmetro que passa por ele é `alturaEsquerda + alturaDireita`.
- **Árvore balanceada**: para cada nó, `|alturaEsquerda - alturaDireita| <= 1`; a versão otimizada propaga `-1` quando alguma subárvore já está desbalanceada, evitando recálculo.
- **Ancestral comum mais próximo (LCA)**: se a raiz for `null` ou igual a um dos nós buscados, retorna a raiz; se as buscas nas duas subárvores retornarem nó não nulo, a raiz atual é o LCA.
- **Views (visões)**: visão esquerda/direita usam BFS e pegam o primeiro/último nó de cada nível; visão superior/inferior usam distância horizontal (horizontal distance) combinada com BFS.

Aplicações: árvore de expressão, codificação de Huffman, árvore binária de busca, heaps/filas de prioridade, roteamento de rede, sistemas de arquivos e parsing de XML/HTML.

Implementação neste repositório: `c/arvore-binaria.c` e `java/src/main/java/com/datastructures/binaryTree/`.
