/* programa que aloca dinamicamente um registro */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct jogador_ {
  char nome[40];
  float salario;
  unsigned gols;
} jogador;

int main() {
  jogador *ptr;// define um ponteiro para o registro 'jogador'
  // aloca dinamicamente um registro do tipo jogador
  ptr = malloc(sizeof(jogador)); 
  // preenchendo o registro
  strcpy(ptr->nome, "Tulipa Goleador");
  ptr->salario = 3000;
  ptr->gols=2;
  // imprimindo o registro
  printf("Contratacao de %s com salario R$ %.1f e %u gols na temporada.\n", ptr->nome, ptr->salario, ptr->gols);
  free(ptr);
  //system("pause");
  return EXIT_SUCCESS;
}
