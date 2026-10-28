## Tokens, Palavras-chave e Identificadores

### Conceito

Um **token** é a menor unidade significativa de um programa em C - a etapa de compilação chamada análise léxica quebra o código-fonte numa sequência desses tokens antes de interpretar sua estrutura.

Os tipos de token em C são:

- **Palavras-chave (keywords)**: reservadas pela linguagem, não podem ser usadas como nome de variável. Exemplos: `int`, `if`, `else`, `while`, `return`, `struct`, `const`, `static`.
- **Identificadores**: nomes dados pelo programador a variáveis, funções, structs, etc. Precisam começar com letra ou `_`, podem conter letras, números e `_`, e não podem ser iguais a uma palavra-chave.
- **Constantes**: valores fixos que não mudam, como `10`, `3.14`, `'a'`, `"texto"`.
- **Operadores**: símbolos que representam operações, como `+`, `-`, `==`, `&&`.
- **Símbolos especiais**: `{ }`, `( )`, `;`, `,`, entre outros, que delimitam blocos, expressões e instruções.

```c
int idade = 25; // int: palavra-chave | idade: identificador | 25: constante | =, ;: símbolos
```

### Boas práticas para identificadores

- Use nomes descritivos (`contador` em vez de `c`, `totalVendas` em vez de `tv`).
- Siga uma convenção consistente no projeto (`snake_case` é comum em C).
- Evite nomes que comecem com `_` seguido de maiúscula ou `__`, reservados pela implementação da linguagem.
