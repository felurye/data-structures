## Merge sort

### Conceito

O **merge sort** e um algoritmo de ordenacao baseado em dividir para conquistar.

Ele divide o vetor em partes menores, ordena essas partes e depois intercala os resultados.

### Merge sort no contexto deste repositorio

Em `merge.c`, o vetor de exemplo e ordenado com duas funcoes:

- `merge_sort`: divide o vetor recursivamente.
- `intercalar`: junta duas metades ordenadas.

A intercalacao usa `vetor_auxiliar` para copiar os elementos em ordem.

### Ideia do algoritmo

1. Divide o vetor ao meio.
2. Ordena a metade esquerda.
3. Ordena a metade direita.
4. Intercala as duas metades ordenadas.

### Complexidade

- Tempo: `O(n log n)` em todos os casos.
- Memoria extra: `O(n)`.
- Estabilidade: preserva a ordem relativa de elementos iguais quando usa `<=` na intercalacao.

### Por que isso e importante para iniciantes

Merge sort mostra recursao aplicada a um problema real e apresenta a estrategia de dividir para conquistar de maneira bem clara.
