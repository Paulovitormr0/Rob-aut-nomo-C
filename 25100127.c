#include "caminho.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void DestruirCaminho (Caminho * C){
    if (C == NULL){
        printf("O ponteiro C esta vazio.");
        return;
    }
    Comando *atual;
    Comando *proximo;
    atual = C->Instrucoes;
    while ( atual != NULL){
        proximo = atual->Proximo;
        free(atual);
        atual = proximo;
    }
    Posicao *atualPos;
    Posicao *proximoPos;
        atualPos = C->Historico;
    while (atualPos != NULL){
        proximoPos = atualPos->Proximo;
        free(atualPos);
        atualPos = proximoPos;  
        }
    free(C);
}

Posicao * DeterminarFim(Caminho * C){

    if(C == NULL){
        printf("O ponteiro C esta vazio.");
        return(NULL);
    }
    return(C->Fim);
}

Posicao * HistoricoPosicoes (Caminho * C){
    if(C == NULL){
        printf("O ponteiro C esta vazio.");
        return(NULL);
    }
    return(C->Historico);
}

int ContarInstrucoes (Caminho * C){
    if(C == NULL){
        printf("O ponteiro C esta vazio.");
        return(-1);
    }

    return(C->N);

}

int CalcularDistanciaTotal(Caminho * C){
    if(C == NULL){
        printf("O ponteiro C esta vazio.");
        return(-1);
    }
    return(C->N);
}

double CalcularDistanciaGeometrica(Caminho * C){
    
    if(C == NULL){
        printf("O ponteiro C esta vazio.");
        return(-1.0);
    }
    double inicioX = C->Inicio->X;
    double inicioy = C->Inicio->Y;
    double fimX = C->Fim->X;
    double fimY = C->Fim->Y;
    double difeX = pow(inicioX - fimX, 2);
    double difeY = pow(inicioy - fimY, 2);
    double raiz = sqrt(difeX + difeY);
    return(raiz);
}
int CalcularDistanciaManhattan(Caminho * C){
    if(C == NULL){
        printf("O ponteiro C esta vazio.");
        return(-1);
    }
    int inicioX = C->Inicio->X;
    int inicioy = C->Inicio->Y;
    int fimX = C->Fim->X;
    int fimY = C->Fim->Y;
    int difeX = abs(inicioX - fimX);
    int difeY = abs(inicioy - fimY);
    int total = difeX + difeY;
    return(total);
}

Caminho * InicializarCaminho(const char *Sequencia, int xInicial, int yInicial){
    if (Sequencia == NULL){
        printf("O ponteiro Sequencia esta vazio.");
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
            DestruirCaminho(Rota);

            printf("Caractere invalido\n");//Deixar mais bonitinha essa msg
                        
            return(NULL);
            
            break;
        }//switch case para mover o robo

        Comando *novoCmd = malloc(sizeof(*novoCmd));

        novoCmd->Direcao = Sequencia[i];
        novoCmd->Proximo = NULL;

        if(ultimoCmd == NULL){
            Rota->Instrucoes = novoCmd;
        }else{
            ultimoCmd->Proximo = novoCmd;
        }

        ultimoCmd = novoCmd;

        Posicao *novaPos = malloc(sizeof(*novaPos));     
        novaPos->X = xAux;
        novaPos->Y = yAux;
        ultimaPos->Proximo = novaPos;
        ultimaPos = novaPos;
        novaPos->Proximo = NULL;
        Rota->N++;
    }
    Rota->Fim = ultimaPos;
    return Rota;
}