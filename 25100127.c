#include "caminho.h"
#include <stdio.h>
#include <string.h>

Caminho * InicializarCaminho(const char *Sequencia, int xInicial, int yInicial){
    if (Sequencia == NULL){
        printf("O ponteiro esta vazio");
        return(NULL);
    } 
    Caminho *Rota = malloc(sizeof(*Rota));

    Posicao *inicio = malloc(sizeof(*inicio));
    inicio -> Proximo = NULL;
    inicio->X = xInicial;
    inicio->Y = yInicial;

    Posicao *historico = inicio;
    Rota->Inicio = inicio;
    Rota->Historico = inicio;
    Rota->Instrucoes = NULL;
    Rota->N = 0;
    int yAux = yInicial;
    int xAux = xInicial;
    

}

int main(){

}