#include "stdio.h"
#include "stdlib.h"
#include <string.h> 
#include "filaPilha_privado.h"
#include "fila_privado.h"

FilaPilha* criarFilaPilha(int tamanho_dados, int *resultado){

    pfila* f = criar(tamanho_dados, resultado);

    if(!f){
        printf("\n Erro na Alocação da Fila\n");
        *resultado = 0;
        return NULL;
    }
    else{
        FilaPilha* FP = malloc(sizeof(FilaPilha));

        if(FP){
            FP->pFila = f;
            FP->tamanho_dados = tamanho_dados;
            *resultado = 1;

            printf("\n FilaPilha alocada com sucesso \n ");
            return FP;

        } else {
            printf("\n Erro na Alocação da Fila Pilha\n");
            *resultado = 0;
            free(f);
            return NULL;
        }

    }
}