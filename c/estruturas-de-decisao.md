## Estruturas de Decisão

### Conceito

Estruturas de decisão controlam qual bloco de código é executado conforme uma condição ser verdadeira ou falsa. Em C, qualquer valor diferente de `0` é considerado verdadeiro, e `0` é falso.

```c
if (condicao) {
    // bloco 1
} else if (outraCondicao) {
    // bloco 2
} else {
    // bloco 3
}
```

### switch

Útil quando uma mesma variável é comparada a vários valores possíveis, como alternativa mais legível a uma cadeia longa de `else if`:

```c
switch (expr) {
    case valor1:
        // ...
        break;
    case valor2:
        // ...
        break;
    default:
        // ...
}
```

- Cada `case` precisa terminar com `break`, senão a execução **cai** (fall-through) para o próximo `case`, mesmo que a condição dele não seja atendida.
- `default` é opcional e trata qualquer valor que não bateu com nenhum `case` anterior.
