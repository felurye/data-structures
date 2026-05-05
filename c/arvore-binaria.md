## Arvore binaria de busca

### Conceito

Uma **arvore binaria de busca** organiza valores de forma hierarquica.

Cada no pode ter ate dois filhos:

- valores menores ficam na subarvore esquerda;
- valores maiores ficam na subarvore direita.

Essa regra permite buscar valores sem precisar percorrer todos os elementos em muitos casos.

### Arvore binaria no contexto deste repositorio

Em `arvore-binaria.c`, cada no guarda uma chave inteira e dois ponteiros:

```c
typedef struct no_arvore {
  int chave;
  struct no_arvore *esquerda;
  struct no_arvore *direita;
} NoArvore;
```

As funcoes principais sao:

- `criar_no`: cria um novo no.
- `inserir_no`: insere seguindo a regra menor-esquerda, maior-direita.
- `buscar_no`: procura uma chave recursivamente.
- `imprimir_em_ordem`: exibe os valores em ordem crescente.
- `calcular_fator_balanceamento`: compara as alturas das subarvores da raiz.

### Ideia do algoritmo

Na busca:

1. Se a raiz atual e `NULL`, o valor nao existe.
2. Se a chave da raiz atual e igual ao valor buscado, a busca terminou.
3. Se o valor e menor, continua pela esquerda.
4. Se o valor e maior, continua pela direita.

### Por que isso e importante para iniciantes

A arvore binaria de busca mostra como recursao e ordenacao podem trabalhar juntas. Ela tambem prepara o caminho para estruturas balanceadas, como AVL e Red-Black.
