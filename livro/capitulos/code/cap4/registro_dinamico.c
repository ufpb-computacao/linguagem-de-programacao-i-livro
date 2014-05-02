/* Aloca e preenche dinamicamente  um vetor de registros */
#include <stdio.h>
#include <stdlib.h>

typedef struct jogador_ {
  char nome[40];
  float salario;
  unsigned gols;
} jogador;

int main() {
  int QUANTIDADE_DE_JOGADORES = 22;
  jogador* jogadores;
  jogadores = malloc(QUANTIDADE_DE_JOGADORES * sizeof(jogador));
  for (int i=0; i<QUANTIDADE_DE_JOGADORES; i++) {
    printf("Digite o nome, salario e gols do jogador %d: \n", i+1);
    scanf("%s", &jogadores[i].nome);
    scanf("%f", &jogadores[i].salario);
    scanf("%u", &jogadores[i].gols);
  }
  printf("Time do Treze: \n");
  for(int i=0; i<QUANTIDADE_DE_JOGADORES; i++) {
    printf("%s ganhando %0.1f \n", jogadores[i].nome,
           jogadores[i].salario);
  }
  
  // Demonstrando notação de ponteiro
  jogador* segundoJogador = &jogadores[1];
  printf("Segundo jogador: %s, recebe R$ %0.1f \n", 
      segundoJogador->nome, segundoJogador->salario);

  free(jogadores);
  //system("pause");
  return EXIT_SUCCESS;
}
