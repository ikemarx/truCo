#include "truco.h"

void embaralhar(Carta baralho[], int num_cartas) {
    int i, j;
    Carta temp;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand((unsigned)time(NULL));

    // Embaralha as cartas usando o algoritmo de Fisher-Yates
    for (i = num_cartas - 1; i > 0; i--) {
        j = rand() % (i + 1);

        // Troca as cartas
        temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}