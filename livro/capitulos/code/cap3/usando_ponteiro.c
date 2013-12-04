#include <stdio.h>
#include <stdlib.h>

int main() {
  int total = 18; // declara uma variável
  int *pt; // declara um ponteiro para int
  pt = &total; // <2> atribui endereço de tot ao ponteiro pt
  
  printf("Valor de total = %d\n", total);
  printf("Valor de pt = %d\n", *pt);
  printf("Endereço de total = %p\n", &total);
  printf("Valor de pt = %p\n", pt);
  
  *pt = *pt + 12; // <3> altera valor de total usando o pt
  
  printf("Apos soma usando ponteiro: total = %d\n", total);
  //system ("pause");
  return 0;
}

