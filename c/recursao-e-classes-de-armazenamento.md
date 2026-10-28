## Recursão e Classes de Armazenamento

### Recursão

Uma função recursiva é uma função que chama a si mesma, sempre com um **caso base** que interrompe a recursão - sem ele, a função chamaria a si mesma indefinidamente até estourar a pilha de chamadas (stack overflow):

```c
int fact(int n) {
    if (n <= 1) return 1;  // caso base
    return n * fact(n - 1); // caso recursivo
}
```

Cada chamada recursiva empilha um novo quadro (stack frame) na call stack, com suas próprias variáveis locais; quando o caso base é atingido, as chamadas vão sendo resolvidas e desempilhadas de trás para frente.

### Classes de armazenamento

Controlam o **tempo de vida** (quando a variável é criada e destruída) e o **escopo** (onde ela pode ser acessada) de uma variável:

| Classe     | Efeito                                                                                                                              |
| ---------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| `auto`     | padrão para variáveis locais - criada ao entrar no bloco, destruída ao sair dele                                                    |
| `static`   | preserva o valor da variável entre chamadas de função; numa variável global, restringe o escopo ao arquivo                          |
| `extern`   | declara uma variável que foi definida em outro arquivo, para compartilhá-la entre arquivos                                          |
| `register` | sugere ao compilador que mantenha a variável num registrador da CPU, para acesso mais rápido (o compilador pode ignorar a sugestão) |

```c
void contador() {
    static int chamadas = 0; // mantém o valor entre chamadas
    chamadas++;
    printf("Chamada número %d\n", chamadas);
}
```

Implementação neste repositório: as operações de `arvore-binaria.c` e `arvore-avl.c` (como `inserir_no` e `calcular_altura`) são bons exemplos práticos de função recursiva com caso base (nó nulo encerrando a recursão).
