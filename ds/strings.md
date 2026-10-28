## Strings

Uma string é uma sequência de caracteres. Em Java, `String` é imutável (qualquer modificação cria uma nova string); para modificações frequentes, usa-se `StringBuilder` (mutável).

| Método (Java)                                               | Uso                                                      |
| ----------------------------------------------------------- | -------------------------------------------------------- |
| `length()`                                                  | tamanho da string                                        |
| `charAt(i)`                                                 | caractere no índice `i`                                  |
| `substring(l, r)`                                           | substring de `l` (incluso) a `r` (exclusivo)             |
| `equals()`                                                  | compara conteúdo (nunca use `==` para comparar conteúdo) |
| `compareTo()`                                               | ordem lexicográfica                                      |
| `toLowerCase()` / `toUpperCase()`                           | muda caixa                                               |
| `contains()`, `indexOf()`, `replace()`, `split()`, `trim()` | busca, substituição e limpeza                            |

Verificação de palíndromo com dois ponteiros, comparando do início e do fim até o centro:

```java
static boolean isPalindrome(String s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s.charAt(l) != s.charAt(r)) return false;
        l++; r--;
    }
    return true;
}
```

Duas strings são anagramas se têm os mesmos caracteres com a mesma frequência - uma forma eficiente é contar a frequência de cada caractere em um array de tamanho 26 (incrementando para a primeira string e decrementando para a segunda; se tudo voltar a zero, são anagramas), em O(n) de tempo.

`StringBuilder` é preferível para concatenação repetida: concatenar com `String` repetidamente custa O(n²) no total, enquanto `StringBuilder.append()` custa O(n).

Implementação neste repositório: `c/casamento-de-padrao.c` implementa casamento de padrões (pattern matching) em strings.
