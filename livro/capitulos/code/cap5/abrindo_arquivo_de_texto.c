#include <stdio.h>

int main(void) {

    char* nomeDoArquivo = "meu-arquivo.txt";
    FILE* arquivo = fopen(nomeDoArquivo, "r");
    if (arquivo != NULL) {
      // arquivo aberto com sucesso...
      // inicia leitura do arquivo

      // fecha arquivo
    } else {
      // exibe mensagem de erro
    }

}
