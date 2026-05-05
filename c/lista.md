## Lista encadeada

### Conceito

Uma **lista encadeada** e uma estrutura linear formada por nos. Cada no guarda um valor e uma referencia para o proximo no.

Diferente de um vetor, seus elementos nao precisam ocupar posicoes continuas na memoria. A ligacao entre eles e feita por ponteiros.

- **Inserir**: cria um novo no e ajusta ponteiros para encaixa-lo na lista.
- **Remover**: desconecta um no da lista e libera sua memoria.
- **Percorrer**: visita os nos seguindo o ponteiro `proximo`.
- **Lista vazia**: a referencia inicial aponta para `NULL`.

### Lista no contexto deste repositorio

Em `lista.c`, a lista e implementada com a estrutura:

```c
typedef struct no_lista {
  int elemento;
  struct no_lista *proximo;
} NoLista;
```

O programa trabalha com insercao e remocao no inicio da lista. Isso torna essas operacoes eficientes, pois nao e necessario percorrer todos os elementos.

As funcoes principais sao:

- `alocar_no`: cria um novo no dinamicamente.
- `inserir_no_inicio`: coloca um valor no comeco da lista.
- `remover_do_inicio`: remove o primeiro no.
- `exibir_lista`: percorre e imprime todos os elementos.
- `liberar_lista`: libera toda a memoria usada antes de encerrar.

### Ideia do algoritmo

Para inserir no inicio:

1. Aloca um novo no.
2. Armazena o valor nele.
3. Faz o novo no apontar para o antigo primeiro no.
4. Retorna o novo no como inicio da lista.

Para remover do inicio:

1. Verifica se a lista esta vazia.
2. Guarda o primeiro no em uma variavel auxiliar.
3. Faz o inicio apontar para o segundo no.
4. Libera o antigo primeiro no.

### Por que isso e importante para iniciantes

A lista encadeada ajuda a entender alocacao dinamica, ponteiros e como uma estrutura pode crescer sem depender de um tamanho fixo previamente definido.
