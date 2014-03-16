#include <stdlib.h>
#include <stdio.h>

int main(void) {
  char* arquivoParaLeitura = "entrada.txt";
  FILE* entrada = fopen(arquivoParaLeitura, "r");
  int bufferSize = 2048;
  char* buffer = calloc(bufferSize, 1);
  if (entrada != NULL) {
    char* arquivoParaEscrita = "saida.txt";
    FILE* saida = fopen(arquivoParaEscrita, "w");
    if (saida != NULL) {
      do {
        char* linha = fgets(buffer, bufferSize, entrada);//<1>
        if (linha!=NULL){
          fputs(buffer, saida);//<2>
        }
      } while (!feof(entrada));
      
      fclose(saida);
    } else {
      // exibe mensagem de erro, não consegue escrever na saída
    }
    
    fclose(entrada);
  } else {
    // exibe mensagem de erro, não consegue ler
  }
}
