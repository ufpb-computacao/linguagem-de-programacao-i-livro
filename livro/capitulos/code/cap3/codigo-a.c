#include <stdio.h>
#include <stdlib.h>

int main() {
  int tot = 18; // declara uma variável
  int *pt;
  declara um ponteiro para int
  pt = &tot;
  
  // atribui endereço de tot ao ponteiro pt
  printf("Valor de tot = %d", tot);
  printf("Valor de pt %d = ", *pt);
  printf("Endereço de total = %p", &tot);
  printf("Valor de pt = %p", pt);
  *pt = *pt + 12; // altera valor de tot usando o pt
  
  printf("Agora tot vale = %d", tot); // imprime novo valor de tot
  system ("pause");
  return 0;
}

