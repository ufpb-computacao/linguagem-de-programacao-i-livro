#include <stdlib.h>
#include <stdio.h>

/* O propósito deste programa é demonstrar a criação e leitura
 * de arquivos no formato binário.
 * Ele simula a criação de um arquivo 'pontuacao.data' que mantém
 * os recordes de jogadores de um jogo. Foi optado por salvar o
 * arquivo no formato binário para evitar que alguém edite a pontução
 * com um editor de texto.
 * A função 'criaArquivoDeRecordistasIniciais' irá criar o arquivo
 * no formato binário, e 'lerArquivoDeRecordistas' irá ler o conteúdo
 * do arquivo. Por fim, a função 'imprimeRecordistas' irá imprir os
 * dados lidos do arquivo, convertendo-os para carácteres, através da
 * função 'printf'.
 */

typedef struct Jogador_{
    int pontuacao;
    char nome[32];
} Jogador; //<1>

Jogador recordistasIniciais[]={ //<2>
    { .nome = "Anjinho", .pontuacao = 50 },
    { .nome = "Bido", .pontuacao = 25 },
    { .nome = "Chico Bento", .pontuacao = 0 }
};

int QUANTIDADE_DA_LISTA = 3; // Anjinho,Bido,Chico 
char* nomeDoArquivoDePontuacao = "pontuacao.data";

void criaArquivoDeRecordistasIniciais(){
    FILE* arquivo = fopen(nomeDoArquivoDePontuacao, "wb");
    if (arquivo != NULL) {
      fwrite(&recordistasIniciais, sizeof(Jogador), //<3>
          QUANTIDADE_DA_LISTA, arquivo); 
      fclose(arquivo);
    } else {
      // mensagem de erro
      fprintf(stderr, "Não foi possível abrir o arquivo: %s\n",
         nomeDoArquivoDePontuacao);
    }
}

Jogador* lerArquivoDeRecordistas(){
    Jogador* jogadores = calloc(QUANTIDADE_DA_LISTA, 
        sizeof(Jogador));
    FILE* arquivo = fopen(nomeDoArquivoDePontuacao, "rb");
    if (arquivo != NULL) {
      fread(jogadores, sizeof(Jogador), QUANTIDADE_DA_LISTA, //<4>
          arquivo);
      fclose(arquivo);
    } else {
      // mensagem de erro
      fprintf(stderr, "Não foi possível abrir o arquivo: %s\n",
         nomeDoArquivoDePontuacao);
    }
    return jogadores;
}

void imprimeRecordistas(Jogador* jogadores){//<5>
    printf("Os seguintes valores foram lidos do arquivo binário:\n");
    for(int i=0; i<QUANTIDADE_DA_LISTA; i++){
        printf("%s %d\n", jogadores[i].nome, jogadores[i].pontuacao);
    }
}

int main(void) {
    criaArquivoDeRecordistasIniciais();
    Jogador* recordistas = lerArquivoDeRecordistas();
    imprimeRecordistas(recordistas);
}
