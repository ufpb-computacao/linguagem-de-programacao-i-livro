/* programa que usa o mesmo ponteiro para alocar memória 
dinamicamente em duas situações diferentes*/

#include <stdio.h>
#include <stdlib.h>
int main() {
  int *ptr; // declara um ponteiro para um inteiro
  ptr = (int*) malloc(sizeof(int)); // aloca memória para inteiro
  if(ptr==NULL) {
    printf ("Não há memória suficiente para alocação.");
    exit(EXIT_FAILURE);
  }
  *ptr=69; // coloca um valor lá
  printf("Valor inteiro = %d \n", *ptr); // imprimi valor
  printf("Localização na memória= %p \n\n", ptr); // imprimi endereço
  free(ptr); // o espaço de memória é liberado

  // usa o mesmo ponteiro para alocar memória para outro inteiro
  ptr = (int*) malloc(sizeof(int)); 

  *ptr=45;
  printf("Valor inteiro = %d \n", *ptr); // imprimi valor
  printf("Localização na memoria= %p \n\n", ptr); // imprimi endereço
  free(ptr); // o espaço de memória é liberado novamente
  
  //  system("pause");
  return EXIT_SUCCESS;
}

