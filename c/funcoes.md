## Funções

### Conceito

Uma função é um bloco de código reutilizável, com uma assinatura formada por tipo de retorno, nome e parâmetros:

```c
int add(int a, int b) {
    return a + b;
}
```

- **Tipo de retorno**: o tipo do valor devolvido pela função (`void` se não retorna nada).
- **Parâmetros**: valores recebidos pela função, declarados entre parênteses.
- **Protótipo**: declaração da assinatura da função antes do `main()`, permitindo usá-la antes de defini-la no arquivo (`int add(int a, int b);`).

### Passagem de parâmetros

C passa argumentos **por valor** por padrão (call by value): a função recebe uma **cópia** do argumento, e alterações dentro da função não afetam a variável original.

```c
void naoMuda(int x) {
    x = 100; // só muda a cópia local
}
```

Para que a função modifique a variável original, é preciso passar o **endereço** dela (um ponteiro), simulando "passagem por referência":

```c
void muda(int *x) {
    *x = 100; // muda o valor na variável original, via ponteiro
}

int main() {
    int n = 5;
    muda(&n);
    printf("%d", n); // 100
}
```

Essa diferença é essencial para entender por que, por exemplo, uma função que recebe um array (que em C "decai" para um ponteiro ao primeiro elemento) consegue alterar o array original, enquanto uma função que recebe um `int` não consegue.
