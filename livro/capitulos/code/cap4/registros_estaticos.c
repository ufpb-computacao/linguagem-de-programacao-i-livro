/* programa que preenche um vetor de registros */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogador_ {
  char nome[40];
  float salario;
  unsigned gols;
} jogador;

int main() {
  int QUANTIDADE_DE_JOGADORES = 22;
  jogador jogadores[QUANTIDADE_DE_JOGADORES];
  for (int i=0; i<QUANTIDADE_DE_JOGADORES; i++) {
    printf("Digite o nome, salario e gols do jogador %d: \n", i+1);
    scanf("%s", &jogadores[i].nome);
    scanf("%f", &jogadores[i].salario);
    scanf("%u", &jogadores[i].gols);
  }
  printf("Jogadores do time: \n");
  for(int i=0; i<QUANTIDADE_DE_JOGADORES; i++) {
    printf("%s ganhando %0.1f \n", jogadores[i].nome, 
        jogadores[i].salario);
  }
  //system("pause");
  return EXIT_SUCCESS;
}
