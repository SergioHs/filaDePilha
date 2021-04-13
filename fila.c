#include "stdio.h"
#include "stdlib.h"
#include <string.h> 
#include "fila_privado.h"

#define qtdmax 100

pfila* criar(int tamanho_dados, int *resultado){

    pfila *f = (pfila*)malloc(sizeof(pfila));
    
    if (!f) {
        printf("Erro ao criar fila!!\n");
        *resultado = 1;
        exit(1);
    }
    f->inicio=NULL;
    f->fim=NULL;
    f->tamanho_dados = tamanho_dados;
    // printf("Valor de f-tamdados: %d\n", f->tamanho_dados);
    *resultado = 0;
    return f;
    
}

void enfileirar(pfila *f, void *elemento, int *resultado){
    
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        return;
    }

    // printf("Alocando noFila el!\n");
    noFila *el = malloc(sizeof(noFila));
    // printf("Alocando dados do noFila el!\n");
    el->dados = (void*) malloc(f->tamanho_dados);

    if(el==NULL) {
        printf("Falha na alocacao do elemento\n");
        *resultado=1;
        return;
    }

    // printf("Definindo dados elemento novo como elemento passado!\n");
    el->dados = elemento;
    // printf("Definindo ponteiro prox do elemento novo para NULL!\n");
    el->prox = NULL;
    
    if(f->inicio==NULL){
        // printf("inicio eh null, entao inicio eh elemento novo");
        f->inicio=el;
    } else { 
        // printf("inicio nao e null, entao fim-prox = elemento novo");
        f->fim->prox=el;
        
    }
    // printf("Fim da fila vira novo elemento\n");
    f->fim=el;
    printf("\nValor no inicio da fila: %s\n", f->inicio);
    printf("Valor no fim da fila: %s\n\n", f->fim);
    *resultado = 0;

}

void* desenfileirar(pfila *f, int *resultado){
    
    noFila *el = malloc(sizeof(noFila));
    // item = malloc(sizeof(noFila));
    // el->dados = (void*) malloc(f->tamanho_dados);

    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        exit(1);
    }
    if(filaVazia(f)==0){
        *resultado=1;
        printf("Fila Vazia!\n");
        exit(1);
    }

    // printf("Valor de f-inicio: %s\n", f->inicio);
    el = f->inicio;

    // printf("Valor de el: %s\n", el);

    // printf("Valor de f-inicio-prox: %s\n", f->inicio->prox);        
    if(f->inicio->prox==NULL) {
        
        f->inicio=NULL;
        f->fim=NULL; 

    } else f->inicio = f->inicio->prox;

    // printf("\nValor removido: %s\n", el);
    // free(el);
    *resultado=0;
    return el;
}

void destruir (pfila *f, int *resultado){

    // printf("Valor de f-inicio %s\n", f->inicio);

    while(f->inicio!=NULL) {
        
        printf("desenfileirando...\n");
        noFila *apagar = malloc(sizeof(noFila));
        apagar = f->inicio;
        f->inicio = f->inicio->prox;
        free(apagar);
    }
    free(f);
    *resultado = 0;
}

int filaCheia(pfila *f){
    
    
    noFila *el = malloc(sizeof(noFila));

    if(f==NULL) {
        printf("Fila nao alocada!\n");
        return 1;
    }
    if(filaVazia(f)==0){
        printf("Fila Vazia!\n");
        return 1;
    }

    int i=1;

    el = f->inicio;
    
    while(el!=f->fim){

        i++;
        el = el->prox;

    }

    if(i<qtdmax) return 1; else return 0;
    
    
}

int filaVazia(pfila *f){

    if(f->inicio==NULL) return 0; else return 1;

}

void consultarpontas (pfila *f, void *inicio, void *fim, int *resultado){
        
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        *resultado=1;
        return;
    }

    if(filaVazia(f)==0){
        printf("Fila Vazia!\n");
    } else {    
        memcpy(inicio, f->inicio, f->tamanho_dados);
        memcpy(fim, f->fim, f->tamanho_dados);

    }
    *resultado = 0;


}

int consultaqtd(pfila *f){
    
    
    if(f==NULL) {
        printf("Fila nao alocada!\n");
        return 1;
    }
    if(filaVazia(f)==0){
        printf("Fila filaVazia!\n");
        return 1;
    }

    int i=1;
    noFila *el = malloc(sizeof(noFila));

    el = f->inicio;
    
    while(el!=f->fim){

        i++;
        el = el->prox;

    }

    printf("%d/%d espaços disponíveis na fila.\n", i, qtdmax); 
       
}