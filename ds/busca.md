## Busca

**Busca linear (sequencial)**: verifica cada elemento um a um até encontrar o alvo ou terminar a lista. Funciona em dados não ordenados.

```java
static int linear(int[] a, int key) {
    for (int i = 0; i < a.length; i++)
        if (a[i] == key) return i;
    return -1;
}
```

**Busca binária**: exige um array ordenado. Divide repetidamente o espaço de busca pela metade, comparando o elemento do meio com o alvo.

```java
static int binary(int[] a, int key) {
    int l = 0, r = a.length - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == key) return m;
        if (a[m] < key) l = m + 1; else r = m - 1;
    }
    return -1;
}
```

| Característica       | Busca Linear                 | Busca Binária           |
| -------------------- | ---------------------------- | ----------------------- |
| Exige array ordenado | Não                          | Sim                     |
| Abordagem            | verifica um a um             | divide e conquista      |
| Tempo (melhor)       | O(1)                         | O(1)                    |
| Tempo (médio/pior)   | O(n)                         | O(log n)                |
| Espaço               | O(1)                         | O(1)                    |
| Uso                  | dados pequenos/não ordenados | dados grandes/ordenados |

Variações da busca binária sobre um array ordenado: primeira ocorrência (lower bound), última ocorrência (upper bound), posição de inserção e contagem de ocorrências de um valor.

**Busca binária sobre a resposta (Binary Search on Answer)**: em vez de buscar em um array, faz busca binária sobre o espaço de possíveis respostas. Aplica-se quando a resposta está dentro de um intervalo `[low, high]` e é monotônica (se `X` é possível, qualquer resposta "melhor" que `X` também é). Usa-se uma função `isPossible(mid)` para decidir se o valor do meio é viável, e então reduz o intervalo de busca.

```java
long low = 0, high = maxPossivel, ans = -1;
while (low <= high) {
    long mid = low + (high - low) / 2;
    if (isPossible(mid)) { ans = mid; high = mid - 1; /* tenta melhor */ }
    else low = mid + 1;                                /* tenta maior */
}
```

É uma técnica útil em problemas de minimizar o máximo ou maximizar o mínimo (por exemplo: distribuir vacas em currais maximizando a menor distância entre elas, ou achar a velocidade mínima de comer bananas dentro de um prazo), transformando um problema difícil de força bruta em uma busca O(log n) sobre as respostas possíveis, desde que `isPossible()` seja verificável em tempo razoável.
