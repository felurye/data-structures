## Recursão e Backtracking

Recursão é uma função que chama a si mesma para resolver um problema, sempre com um caso base que interrompe a cadeia de chamadas e um caso recursivo que resolve um subproblema menor:

```java
static int fact(int n) {
    if (n <= 1) return 1;       // caso base
    return n * fact(n - 1);     // caso recursivo
}
```

Cada chamada recursiva empilha um quadro na pilha de chamadas (call stack); complexidade de tempo e espaço costumam ser O(n) para recursões lineares como o fatorial.

Roteiro para resolver um problema com recursão: definir o estado/parâmetros da função, escrever a condição de parada (caso base), resolver um subproblema menor (caso recursivo) e confiar no resultado recursivo para construir a resposta.

**Backtracking** é recursão que escolhe, explora e depois desfaz uma escolha, tentando sistematicamente todas as possibilidades para encontrar soluções válidas sob restrições:

```java
void solve(State s) {
    if (isGoal(s)) { save(s); return; }
    for (Choice c : choices(s)) {
        apply(c);         // faz uma escolha
        solve(nextState);  // explora
        undo(c);           // desfaz a escolha (backtrack)
    }
}
```

Um exemplo clássico é o padrão de subconjuntos (subset pattern): para cada elemento, há duas escolhas - incluir ou excluir do subconjunto atual - formando uma árvore de decisão binária. Usos comuns de backtracking: gerar todos os subconjuntos de um conjunto, gerar todas as permutações, o problema das N-rainhas, busca de caminhos em labirintos/grades e problemas de satisfação de restrições.
