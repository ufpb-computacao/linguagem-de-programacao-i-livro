/* O propósito deste programa é demonstrar a estrutura geral 
* de um program na linguagem C.
* Ele possui uma variável global 'NUMERO_DE_ITERACOES', que determina
* quantas vezes serão invocadas a função 'imprime_mensagem'.
*/

// Diretivas de pré-compilação
#include <stdio.h>
#include <stdlib.h>

// Declarações globais
int NUMERO_DE_ITERACOES = 3;

// Definição de protótipo de funções ou sub-rotinas usadas no programa
void imprime_mensagem(); // protótipo

int main() { // início do main
  for (int i=0; i < NUMERO_DE_ITERACOES; i++ ){
    imprime_mensagem();
  }
  return EXIT_SUCCESS;
} // final do main

void imprime_mensagem(){ // implementação da função
   printf("Não sei, só sei que foi assim.\n");
}
