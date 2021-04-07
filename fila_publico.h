typedef struct Fila pFila;

pFila* cria (int tamanhoDados, int *resultado);

void destroi (pFila *f, int *resultado);

void insere (pFila *f, void *elemento, int *resultado);

void* remove (pFila *f, int *resultado);