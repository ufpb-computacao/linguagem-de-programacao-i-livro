#include <stdio.h>
#include <stdlib.h>
int main ()
{
  float s0 = 3.0, v0 = 10.0, a = 5.0, t = 3.0;
  float s, v;
  movimento (s0, v0, a, t, &s, &v);
  printf ("%f %f\n", s, v);
  //system ("pause");
  return EXIT_SUCCESS;
}
