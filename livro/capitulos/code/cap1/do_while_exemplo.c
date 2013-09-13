#include <stdio.h>

int main(void) {
  int i;
  do{
    printf ("\nEscolha a fruta pelo numero:\n");
    printf ("\t(1)...Mamao\n");
    printf ("\t(2)...Abacaxi\n");
    printf ("\t(3)...Laranja\n");
    scanf("%d", &i);
  } while ((i<1) || (i>3)); // <1>

  return 0;
}
