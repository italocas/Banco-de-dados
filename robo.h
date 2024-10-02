#ifndef ROBO_H
#define ROBO_H

typedef struct Ponto {
    int X;
    int Y;
    struct Ponto *Proximo;
} Ponto;

typedef struct Caminho {
    Ponto *Origem;
    int N;  // Numero de pontos percorridos
    int Distancia; // Distancia total percorrida
} Caminho;

Caminho *iniciarCaminho(int N);
Ponto *Final(Caminho *C);
int Distancia(Caminho *C);

#endif // ROBO_H

