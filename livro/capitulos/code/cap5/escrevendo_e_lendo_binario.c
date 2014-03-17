#include <stdlib.h>
#include <stdio.h>

typedef struct Jogador_{
    int pontuacao;
    char nome[32];
} Jogador; //<1>

Jogador recordistasIniciais[]={ //<2>
    { .nome = "Anjinho", .pontuacao = 50 },
    { .nome = "Bido", .pontuacao = 25 },
    { .nome = "Chico Bento", .pontuacao = 0 }
};

int QUANTIDADE_DA_LISTA = 3;
char* nomeDoArquivoDePontuacao = "pontuacao.data";

void criaArquivoDeRecordistasIniciais(){
    FILE* arquivo = fopen(nomeDoArquivoDePontuacao, "wb");
    if (arquivo != NULL) {
      fwrite(&recordistasIniciais, sizeof(Jogador), //<3>
          QUANTIDADE_DA_LISTA, arquivo); 
      fclose(arquivo);
    } else {
      // exibe mensagem de erro
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
      // exibe mensagem de erro
    }
    return jogadores;
}

void imprimeRecordistas(Jogador* jogadores){//<5>
    for(int i=0; i<QUANTIDADE_DA_LISTA; i++){
        printf("%s %d\n", jogadores[i].nome, jogadores[i].pontuacao);
    }
}

int main(void) {
    criaArquivoDeRecordistasIniciais();
    Jogador* recordistas = lerArquivoDeRecordistas();
    imprimeRecordistas(recordistas);
}
