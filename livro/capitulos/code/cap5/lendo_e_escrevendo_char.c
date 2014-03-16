#include <stdio.h>

int main(void) {
  char* arquivoParaLeitura = "entrada.txt";
  FILE* entrada = fopen(arquivoParaLeitura, "r");//<1>
  if (entrada != NULL) {//<2>
    char* arquivoParaEscrita = "saida.txt";
    FILE* saida = fopen(arquivoParaEscrita, "w");//<1>
    if (saida != NULL) {//<2>
      int charLido;
      do {
        charLido = fgetc(entrada);//<3>
        if (charLido!=EOF){//<4>
          fputc(charLido, saida);//<3>
        }
      } while (!feof(entrada));//<4>
      
      fclose(saida);//<5>
    } else {
      // exibe mensagem de erro, não consegue escrever na saída
    }
    
    fclose(entrada);//<5>
  } else {
    // exibe mensagem de erro, não consegue ler
  }
}
