## Manipulação de Bits

Operações diretamente sobre os bits de um número, úteis para otimizar soluções, em programação de baixo nível, criptografia e programação competitiva.

| Operador                | Símbolo | Efeito                          |
| ----------------------- | ------- | ------------------------------- |
| AND                     | `&`     | 1 se ambos os bits forem 1      |
| OR                      | `\|`    | 1 se algum bit for 1            |
| XOR                     | `^`     | 1 se os bits forem diferentes   |
| NOT                     | `~`     | inverte todos os bits           |
| Deslocamento à esquerda | `<<`    | multiplica por 2 a cada posição |
| Deslocamento à direita  | `>>`    | divide por 2 a cada posição     |

Operações comuns sobre o i-ésimo bit de `n`:

```java
boolean isSet = (n & (1 << i)) != 0;   // checar se o bit i está ligado
n = n | (1 << i);                       // ligar o bit i
n = n & ~(1 << i);                      // desligar o bit i
n = n ^ (1 << i);                       // alternar (toggle) o bit i
```

Propriedades úteis: `n & (n - 1)` remove o bit menos significativo que está ligado (usado para contar bits ligados, algoritmo de Brian Kernighan, e para checar se um número é potência de 2: `n > 0 && (n & (n - 1)) == 0`); `n & (-n)` isola o bit menos significativo ligado; `a = a ^ b; b = a ^ b; a = a ^ b;` troca duas variáveis sem usar uma variável temporária (funciona apenas com variáveis, não com expressões como `arr[i]` e `arr[j]`).

Aplicações: contar o número de bits 1 em um número, checar se um número é potência de 2, encontrar o número que falta em um array, encontrar números que não se repetem (problema "Single Number"), geração de subconjuntos usando bits como máscara e otimizações de baixo nível.
