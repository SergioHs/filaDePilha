typedef struct Fila pFila;

pFila* criaFila (int tamanho_dados, int *resultado);
void destroiFila (pFila *f, int *resultado);
void enfileirar (pFila *f, void *elemento, int *resultado);
void* desenfileirar (pFila *f, int *resultado);

// opcionais
void consultarpontas (pFila *f, void *inicio, void *fim, int *resultado);
int consultaqtd(pFila *f);