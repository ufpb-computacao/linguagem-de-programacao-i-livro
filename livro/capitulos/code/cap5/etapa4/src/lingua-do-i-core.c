#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lingua-do-i-core.h"

bool arquivoAbertoComSucesso(FILE* arquivo) {
	return arquivo != NULL;
}

/*
Efeito colateral: cabeçote de leitura vai para o início do arquivo
*/
int lerTamanhoDoArquivo(FILE* arquivo) {
	fseek(arquivo, 0, SEEK_END); // vai para o final do arquivo
	int tamanho = ftell(arquivo); // pega posição atual (final)

	fseek(arquivo, 0, SEEK_SET); // volta para o início
	return tamanho;
}

char* lerConteudoDeArquivoArberto(FILE* arquivo) {
	int tamanhoDoArquivo = lerTamanhoDoArquivo(arquivo);
	char* conteudo = calloc(1, tamanhoDoArquivo + 1); // 7.22.3.2 The calloc function

	fread(conteudo, tamanhoDoArquivo, 1, arquivo); // 7.21.8.1 The fread function

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
