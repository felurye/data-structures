## Complexidade de Tempo e Espaço

Complexidade é a forma de medir quanto tempo (complexidade de tempo) ou memória (complexidade de espaço) um algoritmo consome em função do tamanho da entrada (`n`).

- **Big-O (O)**: limite superior - o pior caso.
- **Omega (Ω)**: limite inferior - o melhor caso.
- **Theta (Θ)**: limite restrito - quando o melhor e o pior caso coincidem.

Ordem de crescimento, da mais rápida para a mais lenta: `O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ) < O(n!)`.

Regra prática para contar complexidade em loops: um loop simples que percorre `n` elementos é `O(n)`; loops aninhados multiplicam (`O(n) * O(n) = O(n²)`); loops sequenciais somam (mas a maior ordem domina o resultado final). A "regra de ouro" é sempre olhar para o loop que cresce mais rápido em função de `n` - ele determina a complexidade total.
