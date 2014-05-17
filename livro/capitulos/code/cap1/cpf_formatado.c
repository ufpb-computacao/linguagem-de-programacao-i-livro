#include <stdio.h>
#include <stdlib.h>

/** O propósito deste programa é demonstrar a leitura e impressão
* de um CPF, salvando-o em variável do tipo 'long long'.
*/

int main(void) {
  long long cpf; // variável long long, onde será salvo o cpf
  
  printf("Digite um CPF, somente os números: ");
  scanf("%lld", &cpf); // ler o cpf, utilizando o formato %lld

  // Imprime o cpf, incluindo zeros a esquerda, se necessário.
  printf("CPF lido: %011lld \n", cpf);

  return EXIT_SUCCESS;
}
