## Manipulação de Arquivos em C

### Conceito

Um ponteiro de arquivo (`FILE *fp`) identifica e dá acesso a um arquivo dentro do programa. O fluxo típico de uso é:

```
Programa -> fopen() -> Leitura/Escrita -> fclose()
```

### Funções de `stdio.h`

| Função                                       | Uso                                                      |
| -------------------------------------------- | -------------------------------------------------------- |
| `fopen(nome, modo)`                          | abre um arquivo, retorna `FILE*` ou `NULL` se falhar     |
| `fclose(fp)`                                 | fecha o arquivo, libera recursos                         |
| `fprintf(fp, ...)`                           | escreve dados formatados (como `printf`, mas em arquivo) |
| `fscanf(fp, ...)`                            | lê dados formatados (como `scanf`, mas de arquivo)       |
| `fgetc(fp)` / `fputc(ch, fp)`                | lê/escreve um único caractere                            |
| `fgets(buffer, size, fp)` / `fputs(str, fp)` | lê/escreve uma linha (string)                            |

```c
FILE *fp = fopen("dados.txt", "w");
if (fp == NULL) {
    printf("Erro ao abrir arquivo");
    return 1;
}
fprintf(fp, "Olá, arquivo!\n");
fclose(fp);
```

### Modos de abertura

| Modo             | Descrição                                                |
| ---------------- | -------------------------------------------------------- |
| `r`              | leitura (o arquivo precisa existir)                      |
| `w`              | escrita (cria um novo arquivo ou **trunca** o existente) |
| `a`              | acréscimo/append (cria o arquivo se não existir)         |
| `r+`, `w+`, `a+` | variações com leitura e escrita combinadas               |

Sempre feche o arquivo com `fclose()` depois de usá-lo, para garantir que os dados em buffer sejam de fato gravados em disco e os recursos do sistema operacional sejam liberados.
