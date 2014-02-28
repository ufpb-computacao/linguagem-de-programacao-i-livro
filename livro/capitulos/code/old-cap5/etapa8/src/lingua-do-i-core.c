#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // <1>
#include "lingua-do-i-core.h"

bool arquivoAbertoComSucesso(FILE* arquivo) {
	return arquivo != NULL;
}

/*Efeito colateral:
Cabeçote de leitura vai para o início do arquivo.*/
int lerTamanhoDoArquivo(FILE* arquivo) {
	fseek(arquivo, 0, SEEK_END); // vai para o final do arquivo
	int tamanho = ftell(arquivo); // pega posição atual (final)

	fseek(arquivo, 0, SEEK_SET); // volta para o início
	return tamanho;
}

char* lerConteudoDeArquivoArberto(FILE* arquivo) {
	int tamanhoDoArquivo = lerTamanhoDoArquivo(arquivo);
	// 7.22.3.2 The calloc function
	char* conteudo = calloc(1, tamanhoDoArquivo+1);

	// 7.21.8.1 The fread function
	fread(conteudo, tamanhoDoArquivo, 1, arquivo);

	return conteudo;
}

char* lerConteudoDoArquivo(char* nomeDoArquivo) {
	char* conteudo;

	FILE* arquivo = fopen(nomeDoArquivo, "r");
	if (arquivoAbertoComSucesso(arquivo)) {
		conteudo = lerConteudoDeArquivoArberto(arquivo);
		fclose(arquivo); // fecha arquivo
	} else {
		conteudo = NULL;
	}

	return conteudo;
}

char traduzCaracterParaLinguaDoI(char original){ // <2>
	char resposta;

	switch (original) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		resposta = 'i';
		break;
	default:
		resposta = original;
	}

	return resposta;
}

char* traduzParaLingaDoI(char* mensagemOriginal){ // <3>
	int tamanhoDaMensagem = strlen(mensagemOriginal);
	char* resposta = calloc(1, tamanhoDaMensagem+1); // <4>

	for(int i=0; i<tamanhoDaMensagem; i++){
		char caracterDaMensagemOriginal = mensagemOriginal[i];
		resposta[i] = traduzCaracterParaLinguaDoI(
				caracterDaMensagemOriginal);
	}

	return resposta;
}
