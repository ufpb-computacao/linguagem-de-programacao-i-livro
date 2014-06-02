/* programa que usa uma função para calcular a soma e 
 * subtração de dois números inteiros. FORMA INCORRETA*/
#include <stdio.h>
#include <stdlib.h>

void calculadora(int, int, int, int); // protótipo da função

int main() {
    int sub, soma; // declara duas variáveis do tipo int
    calculadora(10, 7, sub, soma);
    printf ("A subtração e soma entre 10 e 7 são %d e %d. \n",
            sub, soma);
    //system("pause");
    return EXIT_SUCCESS;
}

// Corpo da função calculadora
void calculadora(int x, int y, int sub, int soma){
    sub = x - y;
    soma = x + y;
}

