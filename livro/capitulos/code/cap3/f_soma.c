#include <stdio.h>
#include <stdlib.h>

float f_soma(int); // protótipo da função f_soma
int main() {
    float soma; // declara uma variável do tipo float
    int PAR; // declara uma variável do tipo int
    soma=0; // inicializa a variável soma em 0 (zero)
    PAR = 200; // inicializa a variável PAR em 200
    soma = f_soma(PAR);
    printf ("A soma dos números pares em 0 e 200 é %0.1f ", soma);
    system("pause");
    return 0;
}
// Corpo da função f_soma. Soma os números pares entre 200 e zero
float f_soma(int PAR){
    float s=0; // declara e inicializa em 0 uma variável do tipo float
    while (PAR!=0){
        s = s + PAR;
        PAR= PAR - 2;
    }
    return s;
}

