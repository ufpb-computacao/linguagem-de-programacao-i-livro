/* programa que usa uma função para calcular a 
subtração de dois números inteiros*/

#include <stdio.h>
#include <stdlib.h>

int calculadora(int, int); // protótipo da função calculadora

int main() {
  int sub=0; // declara/inicializa uma variável do tipo int
  sub = calculadora(10, 7);
  printf ("A subtração entre 10 e 7 é %d.\n“, sub);
  system("pause");
  return 0;
}

// Corpo da função calculadora
int calculadora(int x, int y){
  return (x - y);
}

