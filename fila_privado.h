#include "fila_publico.h"

typedef struct nodeFila {
    struct pilha *pilha;
    struct nodeFila *ant;
} nodeFila;

typedef struct Fila {
    nodeFila *inicio, *fim;
    int tamanhoDados;

} pFila;

int cheia(pFila *f); // ver qual é o sentido
int vazia(pFila *f);