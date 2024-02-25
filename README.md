# Compilador para expressões aritméticas

Esse trabalho consiste no desenvolvimento de um analisador de expressões aritméticas utilizando técnicas de construção de compiladores. A divisão de arquivos ocorre da seguinte maneira:

#### Analisador Léxico

- analex.c
- analex.h

#### Analisador Sintático

- sint.c

#### Analisador Semântico

- pilha.h

Para utilizar somente o analisador léxico compile o arquivo `analex.c`:

```shell
gcc analex.c -o analex
```

Para utilizar toda a aplicação compile o arquivo `sint.c`:

```shell
gcc sint.c -o sint
```

Execute o arquivo compilado:

```shell
# Somente o analisador léxico
./analex
# Analisador léxico + Arquivo de teste
./analex < teste.txt
# Aplicação completa
./sint.c
# Aplicação completa + Arquivo de teste
./sint.c < teste.txt
```
