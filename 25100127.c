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
    Posicao *ultimaPos = inicio; //guardar sempre o final da lista
    Comando *ultimoCmd = NULL; //guardar sempre o final dos comandos
    for(int i = 0; Sequencia[i] != '\0'; i++){
        switch (Sequencia[i])
        {
        case 'N':
            yAux++;
            break;
        case 'S':
            yAux--;
            break;
        case 'L':
            xAux++;
            break;
        case 'O':
            xAux--;
            break;
        default:
            printf("Caractere invalido");//Deixar mais bonitinha essa msg

            break;
        }//switch case para mover o robo
            Comando *novoCmd = malloc(sizeof(*novoCmd));
            novoCmd->Direcao = Sequencia[i];
            novoCmd->Proximo = NULL;
    } 

}

int main(){

}