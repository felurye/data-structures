## Padrões sobre Arrays: Dois Ponteiros, Janela Deslizante, Soma de Prefixos e Kadane

Quatro técnicas que resolvem muitos problemas sobre arrays e strings em tempo linear, sem força bruta:

**Dois ponteiros (Two Pointers)**: usa dois índices para percorrer a estrutura, reduzindo a complexidade de tempo e eliminando a necessidade de espaço extra. Principais variações:

- **Direções opostas**: um ponteiro no início, outro no fim, movendo-se um em direção ao outro (bom para array ordenado: par com soma alvo, checagem de palíndromo).
- **Mesma direção**: ambos avançam no mesmo sentido (é a base da janela deslizante).
- **Lento e rápido (slow & fast)**: um ponteiro avança 1 passo, o outro 2 - usado para detectar ciclo e achar o meio de uma lista encadeada (técnica de Floyd, tartaruga e lebre).

```java
int left = 0, right = arr.length - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) { /* par encontrado */ break; }
    else if (sum < target) left++;
    else right--;
}
```

**Janela deslizante (Sliding Window)**: mantém uma janela (subarray/substring) e a desliza pela estrutura, evitando recomputação. Útil em problemas de intervalo, subarray ou substring.

- **Tamanho fixo**: a janela tem tamanho `k` constante; ao avançar, soma o novo elemento e subtrai o que saiu.
- **Tamanho variável**: a janela cresce (expande à direita) e encolhe (contrai à esquerda) conforme uma condição do problema.

```java
int left = 0, sum = 0, result = 0;
for (int right = 0; right < n; right++) {
    sum += arr[right];
    while (/* janela inválida */ false) {
        sum -= arr[left];
        left++;
    }
    result = Math.max(result, sum);
}
```

Ambas as técnicas rodam em O(n) de tempo e O(1) de espaço na maioria dos casos.

**Soma de prefixos (Prefix Sum)**: pré-computa `prefix[i] = prefix[i-1] + a[i]` para responder consultas de soma de intervalo (`l` a `r`) em O(1) após o pré-processamento:

```java
int[] prefix = new int[n];
prefix[0] = a[0];
for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + a[i];

// soma de a[l..r]
int rangeSum = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
```

**Algoritmo de Kadane**: encontra a soma máxima de um subarray contíguo em O(n) de tempo e O(1) de espaço. A ideia: em cada posição, decide se estende o subarray atual ou começa um novo a partir dali.

```java
int curr = a[0], best = a[0];
for (int i = 1; i < n; i++) {
    curr = Math.max(a[i], curr + a[i]);
    best = Math.max(best, curr);
}
```

Guia rápido: par/partição -> dois ponteiros; faixa contígua -> janela deslizante ou prefix sum; soma máxima de subarray -> Kadane.
