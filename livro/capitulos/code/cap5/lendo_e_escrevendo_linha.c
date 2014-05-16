#include <stdlib.h>
#include <stdio.h>

/* Este programa demonstra a leitura e escrita de arquivos 
 * sendo realizadas uma linha por vez, através das
 * funções 'fgets' e 'fputs'.
 * Para executar este programa certifique-se de que exista
 * conteúdo no arquivo 'entrada.txt'. Caso o arquivo 'saida.txt'
 * exista, ele será sobrescrito, caso não exista, ele será criado. 
 * Ao final, o conteúdo de 'saida.txt' deve ser o mesmo 
 * de 'entrada.txt'.
 * Ver também: lendo_e_escrevendo_char.c
 */

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
      
      printf("As linhas de %s foram escritos em %s\n", 
        arquivoParaLeitura, arquivoParaEscrita);
      fclose(saida); // fechando arquivoParaEscrita
    } else {
      // exibe mensagem de erro, não consegue escrever na saída
      fprintf(stderr, "Erro na escrita em %s.\n",arquivoParaEscrita);
    }
    
    fclose(entrada); // fechando arquivoParaLeitura
  } else {
    // exibe mensagem de erro na saída padrão de erro
    fprintf(stderr, "Erro na abertura de '%s'.\n",arquivoParaLeitura);
  }
}
