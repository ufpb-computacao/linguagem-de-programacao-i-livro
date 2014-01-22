#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

char* TRADUCAO="Minhis vigiis, tidi iqui.";
char* traduzParaLingaDoI(char* mensagemOriginal){
	return TRADUCAO;
}
