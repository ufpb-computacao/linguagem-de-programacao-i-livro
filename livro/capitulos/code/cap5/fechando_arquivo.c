#include <stdio.h>

/* Este programa demonstra o FECHAMENTO de um arquivo, 
 * através da função 'fclose'.
 * Supondo que o arquivo 'entrada.txt' exista e a operação de 
 * abertura foi realizada com sucesso, após a finalização da leitura
 * do arquivo (não mostrado aqui), o arquivo deve ser fechado quando
 * não foi mais utilizado.
 */

int main(void) {
    char* nomeDoArquivo = "entrada.txt";
    FILE* arquivo = fopen(nomeDoArquivo, "r");
    if (arquivo != NULL) {
      printf("Arquivo aberto com sucesso...\n");
      // inicia leitura do arquivo

      printf("Fechando o arquivo...\n");
      fclose(arquivo); // <1> fechando arquivo
    } else {
      // exibe mensagem de erro
      fprintf(stderr, "Erro na abertura de '%s'.\n", nomeDoArquivo);
    }
}

