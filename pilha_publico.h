typedef struct Pilha pilha;

Pilha *criaPilha(int capacidade, int tamanho);
int destroiPilha(Pilha *s);
int empilha(Pilha *s, void *src);
int desempilha(Pilha *s, void *dst);

// opcionais
int limpa(Pilha *s);
int topo(Pilha *s, void *el);
