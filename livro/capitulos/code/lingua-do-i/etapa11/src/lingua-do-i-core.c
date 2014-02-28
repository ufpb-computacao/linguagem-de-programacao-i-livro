#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	char* conteudo = calloc(1, tamanhoDoArquivo+1);

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

void salvaConteudo(FILE* arquivoDestino, char* conteudo){
	fprintf(arquivoDestino, "%s", conteudo);
}

char traduzCaracterParaLinguaDoI(char original){
	char resposta;

	switch (original) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		resposta = 'i';
		break;
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		resposta = 'I';
		break;
	default:
		resposta = original;
	}

	return resposta;
}

char* traduzParaLingaDoI(char* mensagemOriginal){
	int tamanhoDaMensagem = strlen(mensagemOriginal);
	char* resposta = calloc(1, tamanhoDaMensagem+1);

	for(int i=0; i<tamanhoDaMensagem; i++){
		char caracterDaMensagemOriginal = mensagemOriginal[i];
		resposta[i] = traduzCaracterParaLinguaDoI(
				caracterDaMensagemOriginal);
	}

	return resposta;
}
