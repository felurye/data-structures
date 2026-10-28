## Tipos de Dados

### Tipos básicos

| Tipo     | Uso                                                                     |
| -------- | ----------------------------------------------------------------------- |
| `int`    | números inteiros                                                        |
| `float`  | números de ponto flutuante (precisão simples)                           |
| `double` | números de ponto flutuante (precisão dupla)                             |
| `char`   | um único caractere                                                      |
| `void`   | ausência de valor (usado em funções sem retorno ou ponteiros genéricos) |

### Modificadores de tipo

Podem ser combinados com os tipos básicos para ajustar faixa de valores e sinal:

- `short` / `long`: reduzem ou aumentam o tamanho em memória (e a faixa de valores) de um tipo, como `short int` ou `long long int`.
- `signed` / `unsigned`: controlam se o tipo aceita valores negativos (`signed`, padrão) ou só valores positivos, dobrando a faixa positiva disponível (`unsigned`).

```c
unsigned int contador = 10; // só aceita valores >= 0
long long int grande = 10000000000LL;
```

### Conversão de tipos (type casting)

- **Implícita**: o compilador converte automaticamente entre tipos compatíveis, geralmente promovendo o tipo menor para o maior (`int` para `float` numa operação mista).
- **Explícita**: o programador força a conversão com um cast, podendo perder precisão (`float` para `int` trunca a parte decimal):

```c
float resultado = 7 / 2;       // 3.0 (divisão inteira primeiro, depois convertida)
float resultado2 = 7 / 2.0;    // 3.5 (um operando já é float, promove a divisão)
int truncado = (int) 3.9;      // 3
```
