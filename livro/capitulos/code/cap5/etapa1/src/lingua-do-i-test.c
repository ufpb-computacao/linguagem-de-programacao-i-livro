#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lingua-do-i-core.h" // <3>

void verificaConteudosSaoIguais(char* conteudo, char* esperado){
	if(conteudo == NULL){
		exit(EXIT_FAILURE); // não pode ser NULL <1>
	}
	int comparacao = strcmp(conteudo, esperado); // <2>
	if (comparacao!=0){
		exit(EXIT_FAILURE); // strings tem que ser iguais <1>
	};
}

char* NOME_DO_ARQUIVO = "musica-trecho.txt";
char* CONTEUDO_ESPERADO = "Oh! Deus, perdoe este pobre coitado";
void testLerConteudoDoArquivo(){
	char* conteudo = lerConteudoDoArquivo(NOME_DO_ARQUIVO); // <3>
	verificaConteudosSaoIguais(conteudo, CONTEUDO_ESPERADO); // <4>
}

int main(void) {
	testLerConteudoDoArquivo(); // <5>

	return EXIT_SUCCESS;
}
