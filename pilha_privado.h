#include "pilha_publico.h"

typedef struct Pilha {
    int topo;
    unsigned int capacidade;
    int tamanhoDados;
    int posicao;
    void *dados;

} Pilha; 

int cheia(Pilha *s);

int vazia(Pilha *s);
