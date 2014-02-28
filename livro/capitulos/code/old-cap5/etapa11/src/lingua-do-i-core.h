#ifndef LINGUA_DO_I_CORE_H_
#define LINGUA_DO_I_CORE_H_

char* lerConteudoDoArquivo(char* nomeDoArquivo);
char* traduzParaLingaDoI(char* mensagemOriginal);
void salvaConteudo(FILE* arquivoDestino, char* conteudo);
char* lerConteudoDeArquivoArberto(FILE* arquivo);

#endif
