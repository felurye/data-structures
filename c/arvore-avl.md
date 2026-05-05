## Arvore AVL

### Conceito

Uma **arvore AVL** e uma arvore binaria de busca autobalanceada.

Depois de insercoes ou remocoes, ela verifica se a diferenca de altura entre as subarvores ficou grande demais. Quando isso acontece, faz rotacoes para recuperar o balanceamento.

- **Fator de balanceamento**: diferenca entre as alturas da direita e da esquerda.
- **Rotacao simples**: corrige desequilibrios em linha.
- **Rotacao dupla**: corrige desequilibrios em zigue-zague.

### AVL no contexto deste repositorio

Em `arvore-avl.c`, cada no guarda:

```c
typedef struct no_avl {
  int chave;
  int fator_balanceamento;
  struct no_avl *esquerda;
  struct no_avl *direita;
} NoAvl;
```

As funcoes centrais sao:

- `inserir_no_avl`: insere uma chave.
- `remover_no_avl`: remove uma chave.
- `calcular_fator_balanceamento`: calcula o desequilibrio de um no.
- `balancear_no`: decide se precisa rotacionar.
- `rotacao_simples_direita` e `rotacao_simples_esquerda`: reorganizam os ponteiros.

### Ideia do algoritmo

Depois de inserir ou remover:

1. Calcula o fator de balanceamento do no atual.
2. Se o fator ficou menor que `-1`, a esquerda esta mais alta.
3. Se ficou maior que `1`, a direita esta mais alta.
4. Escolhe rotacao simples ou dupla conforme o formato do desequilibrio.

### Por que isso e importante para iniciantes

A AVL mostra como manter uma arvore eficiente mesmo quando os dados chegam em ordem desfavoravel. Com balanceamento, busca, insercao e remocao ficam com custo `O(log n)`.
