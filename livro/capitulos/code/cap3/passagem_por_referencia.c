/* programa que usa uma função para calcular a soma e 
subtração de dois números inteiros. FORMA CORRETA*/

#include <stdio.h>
#include <stdlib.h>

void calculadora(int, int, int *, int *); // <1>

int main() {
  int sub, soma; // declara duas variáveis do tipo int
  calculadora(10, 7, &sub, &soma); //<2>
  printf ("A subtração e soma entre 10 e 7 são %d e %d. \n", 
          sub, soma);
  // system("pause");
  return 0;
}

// Corpo da função calculadora
void calculadora(int x, int y, int *ptr1, int *ptr2){// <3>
  *ptr1 = x - y; // <4>
  *ptr2 = x + y; // <4>
}

