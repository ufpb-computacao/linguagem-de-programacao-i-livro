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
      // arquivo aberto com sucesso...
      // inicia escrita no arquivo

      // fecha arquivo
    } else {
      fprintf(stderr, "Erro na abertura de '%s'.\n", nomeDoArquivo);
    }
}
