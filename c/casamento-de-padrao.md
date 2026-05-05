## Casamento de padrao

### Conceito

**Casamento de padrao** e o problema de encontrar ocorrencias de uma sequencia dentro de outra.

Exemplo: procurar o padrao `abbac` dentro de um texto maior formado por caracteres.

### Casamento de padrao no contexto deste repositorio

Em `casamento-de-padrao.c`, o programa cria uma sequencia aleatoria de 100 caracteres entre `a` e `d`, imprime a sequencia e conta quantas vezes o padrao `abbac` aparece.

A versao atual usa o algoritmo **KMP** (_Knuth-Morris-Pratt_).

As funcoes principais sao:

- `construir_lps`: calcula a tabela de prefixos do padrao.
- `contar_ocorrencias_kmp`: percorre o texto sem voltar desnecessariamente.

### Ideia do algoritmo KMP

1. Preprocessa o padrao em uma tabela `lps`.
2. Percorre o texto comparando texto e padrao.
3. Quando ha erro depois de algumas letras certas, usa `lps` para reaproveitar parte da comparacao.
4. Conta cada ocorrencia encontrada.

### Complexidade

- Tempo: `O(n + m)`, em que `n` e o tamanho do texto e `m` o tamanho do padrao.
- Memoria extra: `O(m)`.

### Por que isso e importante para iniciantes

Esse problema aparece em busca de texto, editores, DNA, logs e validadores. O KMP mostra como preprocessamento pode evitar trabalho repetido.
