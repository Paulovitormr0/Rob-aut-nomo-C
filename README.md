# 📍 Robo Autonomo

Este projeto consiste em uma biblioteca em C projetada para inicializar, rastrear e calcular métricas de um **caminho/rota** percorrido por um agente (como um robô) a partir de uma coordenada inicial e de uma sequência de comandos cardinais.

O sistema utiliza estruturas de dados dinâmicas (listas encadeadas) para armazenar o histórico de posições geográficas e a lista de instruções executadas.

---

## 🚀 Funcionalidades

* **Inicialização Dinâmica:** Cria um caminho a partir de coordenadas iniciais (X, Y) e uma string de comandos.
* **Histórico de Movimentação:** Registra cada coordenada visitada passo a passo.
* **Cálculo de Distâncias:**
    * **Distância Total:** Total de passos dados na grade.
    * **Distância Geométrica (Euclidiana):** Distância em linha reta do ponto inicial ao ponto final.
    * **Distância de Manhattan:** Deslocamento absoluto nos eixos X e Y.
* **Gerenciamento de Memória:** Liberação completa de toda a memória alocada dinamicamente para as listas e estruturas.

---

## 🗺️ Comandos Suportados

A movimentação é baseada nos pontos cardinais (em português):
* `N`: Norte (Incrementa `Y`)
* `S`: Sul (Decrementa `Y`)
* `L`: Leste (Incrementa `X`)
* `O`: Oeste (Decrementa `X`)

> ⚠️ **Atenção:** Qualquer caractere diferente destes na sequência de comandos invalida a rota e interrompe a inicialização.

---

## 🛠️ Estrutura das Funções

Abaixo estão as principais funções disponíveis na biblioteca:

| Função | Descrição | Retorno |
| :--- | :--- | :--- |
| `InicializarCaminho(seq, x, y)` | Aloca e processa a rota a partir dos comandos. | `Caminho*` |
| `DestruirCaminho(C)` | Libera toda a memória alocada (Instruções, Histórico e Caminho). | `void` |
| `DeterminarFim(C)` | Retorna o ponteiro para a última posição alcançada. | `Posicao*` |
| `HistoricoPosicoes(C)` | Retorna o ponteiro para o início da lista de posições. | `Posicao*` |
| `ContarInstrucoes(C)` | Retorna a quantidade de comandos executados. | `int` |
| `CalcularDistanciaGeometrica(C)`| Calcula a distância Euclidiana entre o início e o fim. | `double` |
| `CalcularDistanciaManhattan(C)` | Calcula a distância de Manhattan entre o início e o fim. | `int` |

---

## 💻 Exemplo de Uso

Para testar o código, você pode criar um arquivo `main.c` semelhante ao exemplo abaixo:

```c
#include <stdio.h>
#include "caminho.h"

int main() {
    // Inicializa um caminho começando em (0,0) indo para Norte, Leste, Norte
    Caminho *meuCaminho = InicializarCaminho("NLN", 0, 0);

    if (meuCaminho != NULL) {
        printf("Quantidade de passos: %d\n", ContarInstrucoes(meuCaminho));
        
        Posicao *fim = DeterminarFim(meuCaminho);
        printf("Posicao Final: X=%d, Y=%d\n", fim->X, fim->Y);
        
        printf("Distancia Euclidiana: %.2f\n", CalcularDistanciaGeometrica(meuCaminho));
        printf("Distancia Manhattan: %d\n", CalcularDistanciaManhattan(meuCaminho));
        
        // Sempre liberar a memória ao final
        DestruirCaminho(meuCaminho);
    }

    return 0;
}
