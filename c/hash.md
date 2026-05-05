## Tabela hash

### Conceito

Uma **tabela hash** armazena valores em posicoes calculadas por uma funcao hash.

A ideia e transformar uma chave em um indice do vetor para buscar, inserir e remover com custo medio proximo de `O(1)`.

- **Funcao hash**: calcula a posicao inicial de uma chave.
- **Colisao**: ocorre quando duas chaves caem na mesma posicao.
- **Sondagem linear**: resolve colisoes procurando a proxima posicao livre.
- **Marcador removido**: permite remover sem quebrar buscas futuras.

### Tabela hash no contexto deste repositorio

Em `hash.c`, cada entrada guarda um valor e um estado:

```c
typedef struct {
  int valor;
  int estado;
} EntradaHash;
```

Os estados possiveis sao:

- `VAZIO`: posicao nunca usada.
- `OCUPADO`: posicao contem um valor valido.
- `REMOVIDO`: posicao ja foi usada, mas o valor foi removido.

### Ideia do algoritmo

Para inserir:

1. Calcula `calcular_hash(valor)`.
2. Verifica a posicao.
3. Se estiver ocupada por outro valor, avanca uma posicao.
4. Repete ate achar espaco livre ou concluir que a tabela esta cheia.

Para buscar:

1. Comeca no indice calculado pelo hash.
2. Percorre as posicoes seguintes.
3. Para quando encontra o elemento ou uma posicao `VAZIO`.

Para remover:

1. Busca a posicao do elemento.
2. Marca a entrada como `REMOVIDO`.

### Por que isso e importante para iniciantes

Tabelas hash explicam uma das tecnicas mais usadas para dicionarios, mapas e caches. O exemplo tambem mostra por que colisoes precisam de tratamento cuidadoso.
