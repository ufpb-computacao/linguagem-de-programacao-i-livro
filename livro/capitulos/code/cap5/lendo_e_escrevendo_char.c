#include <stdio.h>

/* Este programa demonstra a leitura e escrita de arquivos 
 * sendo realizadas um carácter por vez, através das
 * funções 'fgetc' e 'fputc'.
 * Para executar este programa certifique-se de que exista
 * conteúdo no arquivo 'entrada.txt'. Caso o arquivo 'saida.txt'
 * exista, ele será sobrescrito, caso não exista, ele será criado. 
 * Ao final, o conteúdo de 'saida.txt' deve ser o mesmo 
 * de 'entrada.txt'.
 * Ver também: lendo_e_escrevendo_linha.c
 */

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
      
      printf("Todos as carácteres de %s foram escritos em %s\n", 
        arquivoParaLeitura, arquivoParaEscrita);
        
      fclose(saida);//<5>
    } else {
      // exibe mensagem de erro, na saída padrão de erro 'stderr'
      fprintf(stderr,"Erro na abertura do arquivo 'entrada.txt'.\n");
    }
    
    fclose(entrada);//<5>
  } else {
    // exibe mensagem de erro, não consegue ler
  }
}
