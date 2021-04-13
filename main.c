#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaPilha_publico.h"

int main() {

    int resultado;
    FilaPilha* FP = criarFilaPilha(sizeof(int), &resultado);

    if(!FP){
        printf("\n Deu ruim \n");

    } else {
        printf("\n Deu boa, Fila pilha foi alocada com sucesso e está sendo usada na Main \n");

    }

}