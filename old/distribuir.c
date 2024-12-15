#include "truco.h"

void distribuir(Carta baralho[], Jogador jogadores[NUM_JOGADORES]) {
    int i, j, k;

    // Distribui as cartas para os jogadores
    k = 1;
    for (i = 0; i < NUM_CARTAS_MAO; i++) {
        for (j = 0; j < NUM_JOGADORES; j++) {
            jogadores[j].mao[i] = baralho[k++];
        }
    }
}