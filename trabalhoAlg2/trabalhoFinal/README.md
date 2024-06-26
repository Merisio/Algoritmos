# Extração de Palíndromos e Número Mínimo de Cortes em uma String

Este programa em C utiliza o metodo guloso para identificar e ordenar todos os palíndromos presentes em uma string fornecida pelo usuário. Além disso, ele remove os subpalíndromos redundantes e imprime a string original com barras verticais (|) indicando as posições dos palíndromos identificados.

## Exemplo
Para a string de entrada `bcdddaaadddadabba`, o programa deve produzir:
Palíndromos: bc | dddaaaddd | ad | abba
Número mínimo de cortes: 3

## Como Funciona
1. **int EhPalindromo(char *str, int in, int fin)**:
    - Verifica se uma substring é um palíndromo.

2. **void ordenar_posicoes(int pos[][30], int n)**:
    - Ordena as posições dos palíndromos encontrados com base no comprimento em ordem decrescente.

3. **void achar_todos_palindromos(char *str, int tamanho)**:
    - Identifica todos os palíndromos na string e remove os subpalíndromos redundantes.

## Como Compilar e Executar

No VSCode ou CodeBlocks

1. Baixe e instale um compilador C:

VSCode: Utilize a extensão C/C++ da Microsoft ou configure manualmente com o MinGW ou GCC.
CodeBlocks: Baixe e instale o CodeBlocks, que já inclui o compilador GCC.

2. Salve o código em um arquivo, por exemplo, `extraipalindromos.c`.

3. Compile o programa

No VSCode (com GCC):
Abra um terminal integrado (Ctrl + `) e compile com o GCC ut
    gcc -o palindrome_partition palindrome_partition.c      

No CodeBlocks:
    Abra o projeto `extraipalindromos.c` no CodeBlocks e 

4. Execute o programa

Após compilar com sucesso, execute o programa:

No VSCode, utilize o comando em seu terminal:
    ./palindrome_partition

No CodeBlocks:
    Execute o projeto diretamente no ambiente do CodeBlocks.

5. Informe a string desejada

Após execução do programa informe a string que deseja realizar a verificação, o arquivo `input.txt` possui exemplos de entrada caso necessário 