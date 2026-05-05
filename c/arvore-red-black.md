## Arvore Red-Black

### Conceito

Uma **arvore Red-Black** e uma arvore binaria de busca autobalanceada que usa cores para manter a altura controlada.

Cada no e vermelho ou preto. As regras de cor impedem que um caminho da raiz ate uma folha fique muito maior que outro.

Regras principais:

- A raiz deve ser preta.
- Nos vermelhos nao podem ter filhos vermelhos.
- Todo caminho ate uma folha nula deve ter a mesma quantidade de nos pretos.

### Red-Black no contexto deste repositorio

Em `arvore-red-black.c`, cada no guarda chave, cor, pai e filhos:

```c
struct noh {
  int chave;
  char cor;
  struct noh *dir;
  struct noh *esq;
  struct noh *pai;
};
```

As funcoes principais sao:

- `insercao`: insere um no e corrige a raiz.
- `casos_insercao`: escolhe o caso de cor/rotacao.
- `rotacao_esq` e `rotacao_dir`: reorganizam a arvore.
- `busca`: encontra um valor.
- `imprimir_ERD`: imprime em ordem crescente.

### Ideia do algoritmo de insercao

1. Insere o novo no como em uma arvore binaria de busca.
2. Colore o novo no como vermelho.
3. Se o pai for preto, a arvore continua valida.
4. Se o pai e o tio forem vermelhos, recolore pai, tio e avo.
5. Se houver desequilibrio estrutural, aplica rotacao e recoloracao.

### Por que isso e importante para iniciantes

Arvores Red-Black aparecem em varias bibliotecas de mapas e conjuntos ordenados. Elas mostram uma forma pratica de balancear uma arvore sem exigir balanceamento tao estrito quanto uma AVL.
