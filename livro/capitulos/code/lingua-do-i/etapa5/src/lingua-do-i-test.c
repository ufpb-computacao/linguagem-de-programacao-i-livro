#include <assert.h> // <1>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lingua-do-i-core.h"

void verificaConteudosSaoIguais(char* conteudo, char* esperado){
	assert(conteudo != NULL && "conteúdo não pode ser NULL"); // <2>

	assert( strcmp(conteudo, esperado) == 0
			&& "conteúdo deve ser igual ao esperado"); // <2>
}

char* NOME_DO_ARQUIVO = "musica-trecho.txt";
char* CONTEUDO_ESPERADO = "Oh! Deus, perdoe este pobre coitado";
void testLerConteudoDoArquivo(){
	char* conteudo = lerConteudoDoArquivo(NOME_DO_ARQUIVO);
	verificaConteudosSaoIguais(conteudo, CONTEUDO_ESPERADO);
}

char* MENSAGEM_ORIGINAL="Minhas vogais, tudo aqui.";
char* TRADUCAO_ESPERADA="Minhis vigiis, tidi iqui.";
void testTraducaoParaLinguaDoI(){
	char* mensagemTraduzida = traduzParaLingaDoI(MENSAGEM_ORIGINAL);
	verificaConteudosSaoIguais(mensagemTraduzida, TRADUCAO_ESPERADA);
}

int main(void) {
	testLerConteudoDoArquivo();
	testTraducaoParaLinguaDoI();

	return EXIT_SUCCESS;
}
