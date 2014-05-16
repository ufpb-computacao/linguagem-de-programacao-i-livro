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
      printf("O arquivo 'entrada.txt' foi aberto com sucesso...\n");
      // inicia leitura do arquivo

      // fecha arquivo
    } else {
      // exibe mensagem de erro
      fprintf(stderr, "Erro na abertura de '%s'.\n", nomeDoArquivo);
    }
}
