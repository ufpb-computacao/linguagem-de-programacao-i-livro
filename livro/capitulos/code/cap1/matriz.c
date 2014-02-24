#include <stdio.h>
#include <stdlib.h>

int main(void) {

  double matriz[3][4];

  // Preenchimento de matriz
  for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
      printf("Digite valor a ser preenchido em matriz[%d,%d]: ",i,j);
      scanf("%lf", &matriz[i][j]); // grava na linha i coluna j
    }
  }

  // Impressão de matriz
  printf("Os valores armazenados em matriz são: \n");
  for (int i=0;i<3;i++){
    for (int j=0;j<4;j++){
      printf ("\t%lf",matriz[i][j]);
    }
    printf ("\n");
  }

  return EXIT_SUCCESS;
}
