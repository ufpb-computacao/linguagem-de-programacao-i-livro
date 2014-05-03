#include <stdio.h>
#include <stdlib.h>

int main() {
  float nota1;
  float nota2;
  printf("Digite duas notas não negativas de um(a) aluno(a): ");
  scanf("%f %f", &nota1, &nota2);
  float media = (nota1 + nota2)/2;

  // decisão composta
  if (nota1 < 0 || nota1 >10 || nota2 < 0 || nota2 >10){//condição1
    // bloco de comandos 1
    printf("Alguma nota foi inválida: %f, %f\n", nota1, nota2);
    exit(EXIT_FAILURE);
  } else if (media>=7.0 && media<=10){//condição2
    // bloco de comandos 2
    printf("Situação do aluno(a): APROVADO(A)\n");
  } else if (media>=4 && media<7){//condição3
    // bloco de comandos 3
    printf("Situação do aluno(a): PRECISA FAZER PROVA FINAL\n");
  } else {
    // bloco de comandos default
    printf("Situação do aluno(a): REPROVADO(A)\n");
  }
}
