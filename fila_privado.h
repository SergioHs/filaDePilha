#include "fila_publico.h"

typedef struct fila {

    noFila *inicio, *fim;
    int tamanho_dados;    

} pfila;

typedef struct noFila {
    void *dados;
    noFila *prox;
} noFila;

int filaCheia(pfila *f);
int filaVazia(pfila *f);