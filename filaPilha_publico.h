#ifndef FILAPILHAPUBLICA_H
#define FILAPILHAPUBLICA_H 

#include "filaPilha_privado.h"

FilaPilha* criarFilaPilha(int tamanho_dados, int *resultado);

void destruirFilaPilha(FilaPilha* fp, int *resultado);

void inserir(FilaPilha* fp, void *elemento, int *resultado);

void *remover(FilaPilha* fp, int *resultado);

#endif