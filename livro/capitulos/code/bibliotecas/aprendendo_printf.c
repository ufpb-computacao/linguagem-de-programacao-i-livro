#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    long double meuLD = 19876.649649649;
    double meuDouble = (double) meuLD;
    float meuFloat  = meuDouble;

    printf(
      "Tamanho dos tipos\t float:%d\t double:%d\t long double:%d\n", 
        sizeof (float), sizeof (double), sizeof (long double));

    printf("[%%f]                 [%f][%f]\n", meuFloat, meuDouble);
    printf("Precisão: [%%.4f]     [%.4f]|[%.4f]\n", meuFloat, 
        meuDouble);
    printf("Precisão: [%%.8f]     [%.8f]|[%.8f]\n", meuFloat, 
        meuDouble);
    printf("Precisão: [%%.0f]     [%.0f]|[%.0f]\n", meuFloat, 
        meuDouble);
    
    printf("Campo:    [%%12.4f]   [%12.4f]|[%12.4f]\n", meuFloat, 
        meuDouble);
    printf("Esquerda: [%%-12.4f]  [%-12.4f]|[%-12.4f]\n", meuFloat, 
        meuDouble);
    printf("Zeros:    [%%012.4f]  [%012.4f]|[%012.4f]\n", meuFloat, 
        meuDouble);
    
    printf("long double:[%%Lf]    [%Lf]\n", meuLD);
    printf("long double:[%%.11Lf] [%.11Lf]\n", meuLD);

    // Inteiros
    
    printf("Tamanho dos tipos\tchar:%d\tshort:%d\tint:%d\tlong:%d\tlong long:%d\n", sizeof (char), sizeof (short), sizeof (int), sizeof (long), sizeof (long long));
    printf("Inteiros\n");
    printf("char: %%hhd                  [%hhd; %hhd]\n", 
        SCHAR_MIN, SCHAR_MAX);
    printf("short: %%hd                  [%hd; %hd]\n", 
        SHRT_MIN, SHRT_MAX);
    printf("int: %%d                     [%d; %d]\n", 
        INT_MIN, INT_MAX);
    printf("long: %%ld                   [%ld; %ld]\n", 
        LONG_MIN, LONG_MAX);
    printf("long long: %%lld             [%lld; %lld]\n", 
        LLONG_MIN, LLONG_MAX);

    printf("unsigned char: %%hhu         [%hhu; %hhu]\n", 
        (unsigned char)0, UCHAR_MAX);
    printf("unsigned short: %%hu         [%hu; %hu]\n", 
        (unsigned short)0, USHRT_MAX);
    printf("unsigned int: %%u            [%u; %u]\n", 
        (unsigned int)0, UINT_MAX);
    printf("unsigned long: %%lu          [%lu; %lu]\n", 
        0UL, ULONG_MAX);
    printf("unsigned long long: %%llu    [%llu; %llu]\n", 
        0ULL, ULLONG_MAX);

    printf("hexadecimal (1999): %%x %%X   [%x; %X]\n", 1999, 1999);
    printf("hexadecimal: %%lx %%llX       [%lx; %llX]\n", 
        142342342ul, 2763476238762736763ul);

    return EXIT_SUCCESS;
}
