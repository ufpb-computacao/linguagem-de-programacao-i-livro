#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("sizeof (unsigned int) = %d bits\n",sizeof (unsigned int)*8);
  printf("sizeof (signed int) = %d bits\n", sizeof (signed int)*8);
  printf("sizeof (short int) = %d bits\n", sizeof (short int)*8);
  printf("sizeof (short int) = %d bits\n", sizeof (long long)*8);
  //system ("pause");
  return EXIT_SUCCESS;
}
