#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int tot = 20;
    int *ptr;
    ptr = &tot;
    printf (" %d.", tot);
    printf (" %d", *ptr);
    *ptr = *ptr + tot;
    printf (" %d", tot);
    *ptr = tot + 16;
    printf (" %d\n", tot);
    //system ("pause");
    return EXIT_SUCCESS;
}
