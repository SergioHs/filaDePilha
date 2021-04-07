typedef pFilaDePilha pFilaDePilha;

pFilaDePilha* cria (int tamanhoDados, int *resultado);

void destroi (pFilaDePilha *f, int *resultado);

void insere (pFilaDePilha *f, void *elemento, int *resultado);

void* remove (pFilaDePilha *f, int *resultado);