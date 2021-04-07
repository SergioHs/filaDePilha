#include "stdio.h"
#include "stdlib.h"
#include <string.h> 
#include "fila_privado.h"

#define qtdmax 100

pFila* criar(int tamanhoDados, int *resultado){

    pFila *f = (pFila*)malloc(sizeof(pFila));
    
    if (!f) {
        printf("Erro ao criar fila!!\n");
        *resultado = 1;
        exit(1);
    }
    f->inicio=NULL;
    f->fim=NULL;
    f->tamanhoDados = tamanhoDados;
    // printf("Valor de f-tamdados: %d\n", f->tamanhoDados);
    *resultado = 0;
    return f;
}

void enfileirar(pFila *f, void *elemento, int *resultado){
    
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        return;
    }

    // printf("Alocando nodeFila el!\n");
    nodeFila *el = malloc(sizeof(nodeFila));
    // printf("Alocando dados do nodeFila el!\n");
    el->pilha = (void*) malloc(f->tamanhoDados);

    if(el==NULL) {
        printf("Falha na alocacao do elemento\n");
        *resultado=1;
        return;
    }

    // printf("Definindo dados elemento novo como elemento passado!\n");
    el->pilha = elemento;
    // printf("Definindo ponteiro prox do elemento novo para NULL!\n");
    el->ant = NULL;
    
    if(f->inicio==NULL){
        // printf("inicio eh null, entao inicio eh elemento novo");
        f->inicio=el;
    } else { 
        // printf("inicio nao e null, entao fim-prox = elemento novo");
        f->fim->ant=el;
    }
    // printf("Fim da fila vira novo elemento\n");
    f->fim=el;
    printf("\nValor no inicio da fila: %s\n", f->inicio);
    printf("Valor no fim da fila: %s\n\n", f->fim);
    *resultado = 0;
}

void* desenfileirar(pFila *f, int *resultado){
    
    nodeFila *el = malloc(sizeof(nodeFila));
    // item = malloc(sizeof(nodeFila));
    // el->dados = (void*) malloc(f->tamanho_dados);

    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        exit(1);
    }
    if(vazia(f)==0){
        *resultado=1;
        printf("Fila vazia!\n");
        exit(1);
    }

    // printf("Valor de f-inicio: %s\n", f->inicio);
    el = f->inicio;

    // printf("Valor de el: %s\n", el);
    // printf("Valor de f-inicio-prox: %s\n", f->inicio->prox);        

    if(f->inicio->ant==NULL) {
        f->inicio=NULL;
        f->fim=NULL; 
    } else f->inicio = f->inicio->ant;

    // printf("\nValor removido: %s\n", el);
    // free(el);
    *resultado=0;
    return el;
}

void destruir (pFila *f, int *resultado){

    // printf("Valor de f-inicio %s\n", f->inicio);

    while(f->inicio!=NULL) {
        printf("desenfileirando...\n");
        nodeFila *apagar = malloc(sizeof(nodeFila));
        apagar = f->inicio;
        f->inicio = f->inicio->ant;
        free(apagar);
    }
    free(f);
    *resultado = 0;
}

int cheia(pFila *f){
    
    nodeFila *el = malloc(sizeof(nodeFila));

    if(f==NULL) {
        printf("Fila nao alocada!\n");
        return 1;
    }
    if(vazia(f)==0){
        printf("Fila vazia!\n");
        return 1;
    }

    int i=1;
    el = f->inicio;
    
    while(el!=f->fim){
        i++;
        el = el->ant;
    }
    if(i<qtdmax) return 1; else return 0;
}

int vazia(pFila *f){

    if(f->inicio==NULL) return 0; else return 1;

}


// FUNÇÕES OPCIONAIS - VERIFICAR SE MANTEMOS OU NÃO

void consultarpontas (pFila *f, void *inicio, void *fim, int *resultado){
        
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        return;
    }
    if(vazia(f)==0){
        printf("Fila vazia!\n");
    } else {    
        memcpy(inicio, f->inicio, f->tamanhoDados);
        memcpy(fim, f->fim, f->tamanhoDados);
    }
    *resultado = 0;
}

int consultaqtd(pFila *f){
    
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        return 1;
    }
    if(vazia(f)==0){
        printf("Fila vazia!\n");
        return 1;
    }

    int i=1;
    nodeFila *el = malloc(sizeof(nodeFila));
    el = f->inicio;
    
    while(el!=f->fim){
        i++;
        el = el->ant;
    }
    printf("%d/%d espaços disponíveis na fila.\n", i, qtdmax); 
}