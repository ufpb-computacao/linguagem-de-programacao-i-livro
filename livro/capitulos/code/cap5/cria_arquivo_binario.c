#include <stdio.h>
#include <limits.h>

/**
* O propósito deste programa é criar um arquivo com conteúdo binário,
* para que possa ser utilizado nos demais programas.
* Utilizamos o valor de LLONG_MAX para buscar um valor numérico,
* em seguida, usamos a função 'fwrite' para escrever os bytes no
* formato binário.
* Após a execução deste programa, espera-se que seja criado o arquivo 
* 'arquivo-binario.bin' com conteúdo binário. Para verificar que o
* arquivo é realmente binário, tente abrí-lo em um editor de texto,
* você verá que o arquivo não possui caracteres.
*/

int main(void) {
    char* nomeDoArquivo = "arquivo-binario.bin";
    FILE* arquivo = fopen(nomeDoArquivo, "wb");
    if (arquivo != NULL) {
      // Utiliza o valor de LLONG_MAX para salvar no arquivo
      long long numero_binario = LLONG_MAX;
      // Realiza escrita binária no arquivo com 'fwrite'
      fwrite(&numero_binario, sizeof numero_binario, 1, arquivo);

      printf("Escrevendo %lld, em formato binário, no arquivo: %s\n",
        numero_binario, nomeDoArquivo);

      fclose(arquivo);
    } else {
      fprintf(stderr, "Erro ao abrir o arquivo para escrita: %s\n",
        nomeDoArquivo);
    }
}
