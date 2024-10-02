#include <stdio.h>
#include <stdlib.h>
#include "robo.h"

Caminho *iniciarCaminho(int N) {
    Caminho *C = (Caminho *)malloc(sizeof(Caminho));
    C->Origem = (Ponto *)malloc(sizeof(Ponto));
    C->Origem->X = 0;
    C->Origem->Y = 0;
    C->Origem->Proximo = NULL;
    C->N = N;
    C->Distancia = 0;
    return C;
}

Ponto *Final(Caminho *C) {
    if (C->N < 0) return NULL;

    int x = 0, y = 0;
    int distancia = 0;
    Ponto *atual = C->Origem;

    for (int i = 1; i <= C->N; i++) {
        int passo = (i + 1) / 2;
        if (i % 4 == 1) {
            x += passo;
        } else if (i % 4 == 2) {
            y += passo;
        } else if (i % 4 == 3) {
            x -= passo;
        } else {
            y -= passo;
        }

        Ponto *novoPonto = (Ponto *)malloc(sizeof(Ponto));
        novoPonto->X = x;
        novoPonto->Y = y;
        novoPonto->Proximo = NULL;
        atual->Proximo = novoPonto;
        atual = novoPonto;

        distancia += passo;
    }

    C->Distancia = distancia;
    return atual;
}

int Distancia(Caminho *C) {
    return C->Distancia;
}

int main() {
    int N;
    printf("Digite o numero de ciclos: ");
    scanf("%d", &N);

    Caminho *caminho = iniciarCaminho(N);
    Ponto *pontoFinal = Final(caminho);

    if (pontoFinal != NULL) {
        printf("Ponto final: (%d, %d)\n", pontoFinal->X, pontoFinal->Y);
    } else {
        printf("N e menor que 0, ponto final e NULL.\n");
    }
    printf("Distancia total percorrida: %d\n", Distancia(caminho));

    // Liberacao de memoria
    Ponto *atual = caminho->Origem;
    while (atual != NULL) {
        Ponto *temp = atual;
        atual = atual->Proximo;
        free(temp);
    }
    free(caminho);

    return 0;
}