#include <assert.h>
#include <iso646.h>
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

int traduzCaracteresAcentuados(char* mensagem, int i,
		char* traducao){
	int incremento = 1; // por padrão ler dois bytes
	char primeiroByte = mensagem [i];
	char s = mensagem [i+1]; // segundo byte

	assert (primeiroByte == -61); // prefixo dos acentos
	traducao[i] = primeiroByte; // passa o primeiro byte por padrão

	if (primeiroByte == -61){
		if (s==-94 or s==-86 or s==-76 or s==-69){//âêôû
			traducao[i+1] = -82; //î
		}else if (s==-95 or s==-87 or s==-77 or s==-70){//áéóú
			traducao[i+1] = -83; // í
		}else if (s==-96 or s==-88 or s==-78 or s==-71){//àèòù
			traducao[i+1] = -84; //ì
		}else if (s==-126 or s==-118 or s==-108 or s==-101){//ÂÊÔÛ
			traducao[i+1] = -114; //Î
		}else if (s==-127 or s==-119 or s==-109 or s==-102){//ÁÉÓÚ
			traducao[i+1] = -115; //Í
		}else if (s==-128 or s==-120 or s==-110 or s==-103){//ÀÈÒÙ
			traducao[i+1] = -116; //Ì
		}else if (s==-93 or s==-75){//ãõ
			traducao[i] = -60; //ĩ - substitui primeiro byte
			traducao[i+1] = -87; //ĩ
		}else{
			traducao[i+1] = mensagem[i+1];
		}
	}else if (primeiroByte == -31){
		char terceiro = mensagem[i+2];
		if (s == -70 and terceiro == -67){ // ~e
			traducao[i] = -60; // ĩ
			traducao[i+1] = -87; // ĩ
			incremento = 2; // descartamos o terceiro byte
		}else{
			traducao[i] = primeiroByte;
			traducao[i+1] = s;
			incremento = 1;
		}
	}else if (primeiroByte == -59){
		if ( s == -87 ) { // ũ
			traducao[i] = -60; // ĩ
			traducao[i+1] = -87; // ĩ
		}else{
			traducao[i] = primeiroByte;
			traducao[i+1] = s;
		}
	}else{
		traducao[i] = primeiroByte;
		traducao[i+1] = s;
	}
	return incremento;
}

bool podeSerVogalAcentuada(char caracter) {
	return caracter == -61 or caracter == -31 or caracter == -60
			or caracter == -59;
}

char* traduzParaLingaDoI(char* mensagemOriginal){
	int tamanhoDaMensagem = strlen(mensagemOriginal);
	char* traducao = calloc(1, tamanhoDaMensagem+1);

	for(int i=0; i<tamanhoDaMensagem; i++){
		char caracterDaMensagemOriginal = mensagemOriginal[i];
		if (podeSerVogalAcentuada(caracterDaMensagemOriginal)){
			int incremento = traduzCaracteresAcentuados(
					mensagemOriginal,i,traducao);
			i+=incremento;
		}else{
			traducao[i] = traduzCaracterParaLinguaDoI(
				caracterDaMensagemOriginal);
		}
	}
	return traducao;
}

FILE* determinaEntrada(int argc, const char* argv[]){
	FILE* entrada;
	if (argc == 1){
		entrada = stdin;
	}else{
		entrada = fopen(argv[1], "r");
	}
	return entrada;
}

bool naoChegouNoFinal(FILE* stream){
	return !feof(stream);
}

int TAMANHO_MAXIMO_DA_LINHA = 2048;
char* lerLinhaDaEntrada(FILE* entrada){
	char* linha = calloc(1, TAMANHO_MAXIMO_DA_LINHA);
	return fgets(linha, TAMANHO_MAXIMO_DA_LINHA, entrada);
}

void salvaConteudoNaSaida(char* conteudo, FILE* saida){
	int tamanhoDaMensagem = strlen(conteudo);
	fwrite(conteudo,1,tamanhoDaMensagem,saida);
}

bool tentouLerAposFinalDoArquivo(char* linha){
	return linha == NULL;
}

void traduzFluxoDeEntradaNaSaida(FILE* entrada, FILE* saida){
	bool chegouNoFinalDoArquivo = false;

	while (!chegouNoFinalDoArquivo){
		char* linha = lerLinhaDaEntrada(entrada);
		if (tentouLerAposFinalDoArquivo(linha)) {
			chegouNoFinalDoArquivo = true;
		} else {
			char* traducao = traduzParaLingaDoI(linha);
			salvaConteudoNaSaida(traducao, saida);
		}
	}
}
