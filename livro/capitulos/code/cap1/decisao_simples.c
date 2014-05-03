#include <stdio.h>
#include <stdlib.h>

int main() {
    float nota1;
    float nota2;
    printf("Digite duas notas não negativas de um(a) aluno(a): ");
    scanf("%f %f", &nota1, &nota2);
    
    if (nota1 < 0 || nota2 < 0){
      // Bloco de decisão simples
      printf("Notas não podem ser negativas.\n");
      exit(EXIT_FAILURE);
    }
    
    float media = (nota1 + nota2)/2;
    printf("Media = %f \n", media);
};
