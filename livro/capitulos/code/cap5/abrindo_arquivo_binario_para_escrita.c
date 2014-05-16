#include <stdio.h>

/* Este programa demonstra a abertura de um arquivo binário 
 * através da função 'fopen'.
 * Caso o arquivo 'arquivo-binario.bin' exista, a abertura será 
 * realizada com sucesso. Caso contrário, fopen irá retornar NULL, 
 * indicando que não houve sucesso na abertura.
 * Ver também: abrindo_arquivo_de_texto.c, cria_arquivo_binario.c
 */

int main(void) {
    char* nomeDoArquivo = "arquivo-binario.bin";
    FILE* arquivo = fopen(nomeDoArquivo, "wb");
    if (arquivo != NULL) {
      printf("Arquivo '%s' foi aberto com sucesso.\n", nomeDoArquivo);
      // inicia escrita binária do arquivo

      // fecha arquivo
    } else {
      // exibe mensagem de erro na saída padrão de erro
      fprintf(stderr, "Erro na abertura de '%s'.\n", nomeDoArquivo);
    }
}
