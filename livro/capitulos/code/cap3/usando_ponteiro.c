#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int total = 18; 
  int *pt; // <1> 
  pt = &total; // <2> 
  
  printf("Valor de total = %d\n", total); // <3> 
  printf("Endereço de total = %p\n", &total);// <3>
  printf("Valor de pt = %p\n", pt);// <4>
  printf("Valor de *pt = %d\n", *pt);// <5>
  
  *pt = *pt + 12; // <6> 
  
  printf("Apos soma usando ponteiro: total=%d\n", total);// <7>
  //system ("pause");
  return 0;
}

