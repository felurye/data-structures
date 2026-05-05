## Fila (Queue)

### Conceito

Uma **fila** e uma estrutura linear em que o primeiro elemento inserido e o primeiro a ser removido.

Esse comportamento e conhecido como **FIFO** (_First In, First Out_).

- **Enfileirar**: insere um elemento no final da fila.
- **Desenfileirar**: remove o elemento do inicio.
- **Inicio**: aponta para o elemento mais antigo.
- **Fim**: aponta para o elemento mais recente.
- **Fila vazia**: inicio e fim nao apontam para nenhum no.

### Fila no contexto deste repositorio

Em `fila.c`, a fila usa nos encadeados:

```c
typedef struct no_fila {
  int valor;
  struct no_fila *proximo;
} NoFila;
```

O ponteiro `inicio_fila` representa o inicio da fila, e `fim_fila` representa o ultimo elemento.

As funcoes principais sao:

- `inserir_na_fila`: cria um novo no e o coloca no final.
- `remover_da_fila`: remove o no do inicio.
- `mostrar_fila`: percorre a fila exibindo os valores.
- `mostrar_erro`: exibe mensagem para opcoes invalidas.

### Ideia do algoritmo

Ao inserir:

1. Um novo no e alocado.
2. Se a fila esta vazia, inicio e fim apontam para esse no.
3. Caso contrario, o antigo fim aponta para o novo no.
4. O fim passa a ser o novo no.

Ao remover:

1. O primeiro no e guardado.
2. O inicio passa para o proximo no.
3. O antigo inicio e liberado.

### Por que isso e importante para iniciantes

Filas aparecem em impressoras, atendimento, buffers, escalonamento de processos e percursos em largura em grafos. O exemplo mostra como controlar dois ponteiros para obter insercao e remocao eficientes.
