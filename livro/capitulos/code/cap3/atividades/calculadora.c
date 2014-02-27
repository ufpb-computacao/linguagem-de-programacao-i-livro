#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  float c = 2.5, d = 3.9, s, p;
  calculadora (c, d, &s, &p);
  printf ("%f %f\n", s, p);
  //system ("pause");
  return EXIT_SUCCESS;
}
