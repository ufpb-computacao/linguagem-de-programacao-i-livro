/* programa que soma dois vetores usando alocação dinâmica*/
#include <stdio.h>
#include <stdlib.h>
int* soma_vet(int[], int[]);
int main() {
  int i, *ptr1; // declara um inteiro e um ponteiro para inteiro
  int va[8], vb[8]; // declara dois vetores 8 posições
  for(i=0; i<8; i++) { // preenchendo os vetores va e vb
    va[i]=i;
    vb[i]=i+1;
  }
  ptr1=soma_vet(va, vb); // chamando a função soma_vet
  for(i=0; i<8; i++) { // imprimindo o vetor va
    printf("%d\t", va[i]);
  }
  printf("\n");
  for(i=0; i<8; i++) { // imprimindo o vetor vb
    printf("%d\t", vb[i]);
  }
  printf("\n");
  for(i=0; i<8; i++) { // imprimindo o vetor soma
    printf("%d\t", ptr1[i]);
  }
  printf("\n");
  //system("pause");
  return EXIT_SUCCESS;
}
int* soma_vet(int va[8], int vb[8]) {
  int *ptr2;
  ptr2 = (int*) malloc(8*sizeof(int));
  if(ptr2==NULL) {
    printf ("Não há memória suficiente. O programa será encerrado.");
    exit(EXIT_FAILURE);
  }
  for(int j=0; j<8; j++) {
    ptr2[j]= va[j] + vb[j];
  }
  return ptr2;
}
