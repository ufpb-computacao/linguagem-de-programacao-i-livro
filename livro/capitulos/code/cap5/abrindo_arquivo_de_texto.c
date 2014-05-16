#include <stdio.h>

/* Este programa demonstra a abertura de um arquivo de texto 
 * através da função 'fopen'.
 * Caso o arquivo 'entrada.txt' exista, a abertura será realizada 
 * com sucesso. Caso contrário, fopen irá retornar NULL, indicando
 * que não houve sucesso na abertura.
 * Ver também: abrindo_arquivo_binario_para_escrita.c
 */

int main(void) {
    char* nomeDoArquivo = "entrada.txt";
    FILE* arquivo = fopen(nomeDoArquivo, "r");
    if (arquivo != NULL) {
      printf("Arquivo '%s' foi aberto com sucesso.\n", nomeDoArquivo);
      // inicia leitura de arquivo texto

      // fecha arquivo
    } else {
      // exibe mensagem de erro na saída padrão de erro
      fprintf(stderr, "Erro na abertura de '%s'.\n", nomeDoArquivo);
    }
}
