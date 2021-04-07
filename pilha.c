#include "stdio.h"
#include "stdlib.h"
#include <string.h> 
#include "pilha_privado.h"

Pilha *criaPilha(int capacidade, int tamanho) {

  printf ("Alocando pilha...\n");
  Pilha *res = malloc(sizeof(Pilha));
  if (!res) {
    printf("Erro ao criar pilha!\n");
    exit(1);
  }
  res->capacidade = capacidade;
  res->tamanhoDados = tamanho;
  res->posicao = 0;
  
  printf ("Alocando dados\n");
  if (!(res->dados = malloc(capacidade * tamanho))) {
    printf("Erro ao criar pilha!\n");
    exit(1);
  };

  return res;

}

int destroiPilha(Pilha *s) {

  if (!s) {
    printf("Pilha não alocada!!\n");
    return 1;
  } else {
    free(s->dados);
    free(s);
    return 0;
  }
}

int empilha(Pilha *s, void *src) {
  if (!s) {
    printf("Pilha não alocada!!\n");
    return 1;
  }
  // Calcula a posição
  if(cheia(s)==0){
    printf("Impossivel inserir mais elementos, pilha cheia!!\n");
    return 1;
  } else {
    int pos = s->posicao * s->tamanhoDados;
    // Copia a memória...
    memcpy(s->dados + pos, src, s->tamanhoDados);
    // Aumenta o tamanho...
    s->posicao++;
    return 0;
  }
}

int desempilha(Pilha *s, void *dst) {
  
  if (!s) {
    printf("Pilha não alocada!!\n");
    return 1;
  }

  if(vazia(s)==0){
    printf("Não há mais elementos para remover!\n");
    return 1;
  } else {
    // Diminui o contador...
    s->posicao--;
    // Calcula...
    int pos = s->posicao * s->tamanhoDados;
    // Copia...
    memcpy(dst, s->dados + pos, s->tamanhoDados);
    return 0;
  }
  
}

int cheia(Pilha *s) {
  if(s->posicao==s->capacidade) return 0;
  else return 1;
}

int vazia(Pilha *s) {
  if(s->posicao==0) return 0;
  else return 1;
}

int limpa(Pilha *s) {
  if (!s) {
    printf("Pilha não alocada!!\n");
    return 1;
  }

  if(s->posicao==0){ 
    printf("A pilha já está vazia!\n");
    return 2;
  } else {
    printf("Limpando pilha... \n");
    s->posicao = 0;
    return 0;
  }
}

int topo(Pilha *s, void *el) {

  if (!s) {
    printf("Pilha não alocada!!\n");
    return 1;
  }

  if(vazia(s)==0){
    printf("Não há elementos na pilha!\n");
    return 1;
  } else {
    // Calcula...
    int valor = s->posicao - 1;
    int pos = valor * s->tamanhoDados;
    // Copia...
    memcpy(el, s->dados + pos, s->tamanhoDados);
    return 0;
  }
}