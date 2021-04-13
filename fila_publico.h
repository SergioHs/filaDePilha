typedef struct fila pfila;
typedef struct noFila noFila;

pfila* criar(int tamanho_dados, int *resultado);
void enfileirar(pfila *f, void *elemento, int *resultado);
void* desenfileirar(pfila *f, int *resultado);
void destruir (pfila *f, int *resultado);
void consultarpontas (pfila *f, void *inicio, void *fim, int *resultado);
int consultaqtd(pfila *f);