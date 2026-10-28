## Laços de Repetição

### Tipos de laço

| Laço         | Quando usar                                                                           |
| ------------ | ------------------------------------------------------------------------------------- |
| `for`        | número de repetições conhecido (contador, percorrer um array)                         |
| `while`      | repetições controladas por condição, verificada **antes** de cada iteração            |
| `do...while` | repetições controladas por condição, verificada **depois** (executa ao menos uma vez) |

```c
for (int i = 0; i < 10; i++) { /* ... */ }

while (condicao) { /* ... */ }

do {
    /* ... */
} while (condicao);
```

### Controle de fluxo dentro de laços

- `break`: interrompe o laço imediatamente, mesmo que a condição ainda seja verdadeira.
- `continue`: pula o restante do bloco atual e vai direto para a próxima verificação da condição/iteração.

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) break;     // para no i == 5
    if (i % 2 == 0) continue; // pula os pares, imprime só os ímpares
    printf("%d ", i);
}
```

Laços aninhados (um laço dentro de outro) são comuns ao percorrer estruturas multidimensionais, como uma matriz (array 2D), e custam O(n²) quando ambos percorrem o mesmo tamanho `n`.
