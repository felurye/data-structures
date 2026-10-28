## Programação Dinâmica

Programação Dinâmica (DP) é uma técnica algorítmica para resolver problemas quebrando-os em subproblemas sobrepostos, resolvendo cada subproblema uma única vez e armazenando o resultado para evitar recomputação. É usada principalmente para problemas de otimização.

Dois princípios-chave precisam estar presentes para aplicar DP:

- **Subproblemas sobrepostos**: o problema pode ser quebrado em subproblemas que se repetem.
- **Subestrutura ótima**: a solução ótima do problema pode ser construída a partir das soluções ótimas dos seus subproblemas.

Duas abordagens:

- **Memoization (top-down)**: usa recursão e armazena os resultados em uma tabela (`dp[]`/`dp[][]`); útil quando o espaço de estados é grande, mas nem todos os estados são necessários.
- **Tabulation (bottom-up)**: usa iteração, construindo a tabela a partir dos casos base até a resposta final; geralmente mais eficiente (sem pilha de recursão).

```java
// Top-down (memoization)
int fib(int n, int[] dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

// Bottom-up (tabulation)
int fib(int n) {
    int[] dp = new int[n + 1];
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
```

Roteiro para resolver um problema de DP: definir o estado, escrever a relação de recorrência, identificar o(s) caso(s) base, escolher a abordagem (memoization ou tabulation), calcular a resposta e retornar o resultado final. Todo problema de DP é, na essência, uma recursão com repetição.

Padrões comuns de DP:

| Padrão                              | Significado                          | Exemplos                                         |
| ----------------------------------- | ------------------------------------ | ------------------------------------------------ |
| DP 1D                               | estado depende de um parâmetro       | Fibonacci, escalada de escadas (climbing stairs) |
| DP 2D                               | estado depende de dois parâmetros    | caminhos em grade, LCS, distância de edição      |
| DP de mochila (Knapsack)            | escolhas com restrição de capacidade | mochila 0/1, soma de subconjunto                 |
| DP sobre sequências                 | baseado em prefixos/substrings       | LIS, LCS, particionamento de palíndromo          |
| DP sobre intervalos                 | baseado em início e fim              | multiplicação de cadeia de matrizes              |
| DP com máscara de bits (Bitmask DP) | estado representado com bits         | caixeiro viajante (TSP), atribuições             |
| Digit DP                            | DP sobre os dígitos de um número     | contar números com uma propriedade dada          |

Exemplo clássico - subsequência comum mais longa (LCS) entre duas strings `s1` e `s2`:

```java
if (s1.charAt(i - 1) == s2.charAt(j - 1))
    dp[i][j] = 1 + dp[i - 1][j - 1];
else
    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
```

Complexidade O(n\*m) de tempo e espaço, onde `n` e `m` são os tamanhos das strings.

Otimização de espaço: muitos problemas de DP podem ser reduzidos de 2D para 1D, ou até para poucas variáveis, quando cada estado depende apenas de estados recentes (como no Fibonacci, em que basta guardar os dois últimos valores em vez de uma tabela inteira).

Quando pensar em DP: o problema tem subproblemas sobrepostos, uma solução recursiva está recomputando os mesmos estados repetidamente, a solução ótima pode ser construída a partir de subsoluções, e as restrições do problema permitem armazenar estados em uma tabela. Regra prática: se a recursão pura está dando "Time Limit Exceeded", pense em DP; se a força bruta é lenta, pense em DP - DP transforma problemas exponenciais em soluções polinomiais.
