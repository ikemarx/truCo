#include "truco.h"

void definir_vira_e_manilhas(Carta baralho[], Mesa *mesa, int num_numeros) {
    // A vira será a primeira carta do baralho
    mesa->vira = baralho[0];
    
    // Calcula o próximo número em relação à vira
    int proximo_numero = (mesa->vira.numero + 1) % num_numeros;

    // Marca as cartas com o próximo poder como manilhas
    for (int i = 0; i < num_numeros; i++) {
        if (baralho[i].numero == proximo_numero) {
            baralho[i].manilha = 1;
        }
    }
}