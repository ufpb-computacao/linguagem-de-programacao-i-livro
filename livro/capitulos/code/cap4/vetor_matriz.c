/* programa que usa um vetor para alocar dinamicamente uma matriz */
#include <stdio.h>
#include <stdlib.h>
int main() {
  int l=4, c=3; // declara as linhas e colunas da matriz

  float *mtr; // declara dois floats e um ponteiro para float
  mtr = (float*) malloc(c*l*sizeof(float)); // alocação dinâmica
  if(mtr==NULL) {
    printf ("Memoria insuficiente para alocar os c*l elementos.");
    exit(EXIT_FAILURE);
  }
// preenchendo o vetor (diretamente) e a matriz (indiretamente)
  for(int i=0; i<l; i++) {
    for(int j=0; j<c; j++) {
      mtr[i*c + j]= (9*i+j)/4.0;
    }
  }
// imprimindo a matriz
  for (int i=0; i<l; i++) {
    for (int j=0; j<c; j++) {
      printf ("%0.1f\t", mtr[i*c + j]);
    }
    printf ("\n");
  }
  printf("\n");
  free(mtr); // libera do espaço de memória alocado dinamicamente
  //system("pause");
  return EXIT_SUCCESS;
}
