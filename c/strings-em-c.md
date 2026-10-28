## Strings em C

### Conceito

Uma string em C é, na verdade, um **array de caracteres terminado pelo caractere nulo `'\0'`** - não existe um tipo `string` nativo como em outras linguagens:

```c
char name[] = "Abhi";
// A  b  h  i  \0
// 0  1  2  3  4
```

O `'\0'` marca o fim da string e é adicionado automaticamente por literais de string (`"Abhi"`); ao construir uma string manualmente (char a char), é preciso adicioná-lo você mesmo, senão funções como `printf("%s", ...)` vão continuar lendo memória além do array até encontrar um `'\0'` por acaso.

### Funções da biblioteca `string.h`

| Função                  | Uso                                                                         |
| ----------------------- | --------------------------------------------------------------------------- |
| `strlen(s)`             | retorna o tamanho da string (sem contar o `'\0'`)                           |
| `strcpy(dest, src)`     | copia `src` para `dest`                                                     |
| `strncpy(dest, src, n)` | copia até `n` caracteres, mais seguro contra overflow                       |
| `strcat(dest, src)`     | concatena `src` ao final de `dest`                                          |
| `strcmp(s1, s2)`        | compara duas strings (0 se iguais, <0 ou >0 conforme a ordem lexicográfica) |

```c
char destino[50] = "Olá, ";
strcat(destino, "mundo!");
printf("%s", destino); // "Olá, mundo!"
```

### Cuidados comuns

- Sempre reserve espaço suficiente no array de destino, incluindo 1 posição extra para o `'\0'`.
- `scanf("%s", ...)` lê até o próximo espaço em branco; para ler uma linha inteira (com espaços), use `fgets()`.
- Strings são comparadas com `strcmp()`, nunca com `==` (que compararia os endereços dos arrays, não o conteúdo).
