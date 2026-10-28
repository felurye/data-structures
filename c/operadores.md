## Operadores

### Categorias

| Categoria              | Operadores         |
| ---------------------- | ------------------ |
| Aritméticos            | `+ - * / %`        |
| Relacionais            | `== != > < >= <=`  |
| Lógicos                | `&& \|\| !`        |
| Atribuição             | `= += -= *= /= %=` |
| Bit a bit (bitwise)    | `& \| ^ ~ << >>`   |
| Incremento/decremento  | `++ --`            |
| Condicional (ternário) | `?:`               |

### Observações importantes

- `%` (módulo) só funciona com inteiros; para resto de ponto flutuante existe `fmod()` em `math.h`.
- `++`/`--` têm versão **pré-fixada** (`++i`, incrementa antes de usar o valor) e **pós-fixada** (`i++`, usa o valor e depois incrementa).
- Operadores lógicos (`&&`, `||`) fazem **curto-circuito**: em `a && b`, se `a` for falso, `b` nem é avaliado.
- Operador ternário substitui um `if/else` simples de uma linha:

```c
int maior = (a > b) ? a : b;
```

### Precedência

Quando em dúvida sobre a ordem de avaliação de uma expressão com vários operadores, use parênteses - deixa a intenção explícita e evita depender de decorar a tabela de precedência da linguagem.
