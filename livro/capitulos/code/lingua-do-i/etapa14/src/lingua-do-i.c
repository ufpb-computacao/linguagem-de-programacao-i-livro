#include <stdio.h>
#include <stdlib.h>
#include "lingua-do-i-core.h"

int main(int argc, const char* argv[]) {

	FILE* entrada = determinaEntrada(argc, argv);

	if (entrada){
		char* conteudo=lerConteudoDeArquivoArberto(entrada);
		char* mensagem=traduzParaLingaDoI(conteudo);
		salvaConteudo(stdout, mensagem);
	}else{
		fprintf(stderr, "Problema ao abrir arquivo: %s\n",
				argv[1]);
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
