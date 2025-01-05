#include <iostream>
#include "Jogo.h"

int main() {
    std::cout << "=== Bem-vindo ao Truco! ===\n";

    Jogo jogo;
    jogo.inicializarJogo();

    Equipe* vencedor = nullptr;
    while (!vencedor) {
        jogo.jogarRodada();
        vencedor = jogo.verificarVencedor();

        // Mostra o placar depois de cada rodada.
        std::cout << "\n=== Placar ===\n";
        std::cout << jogo.getEquipe1()->getNome() << ": " << jogo.getEquipe1()->getPontos() << " pontos\n";
        std::cout << jogo.getEquipe2()->getNome() << ": " << jogo.getEquipe2()->getPontos() << " pontos\n";
    }

    std::cout << "\n" << vencedor->getNome() << " venceu o jogo!\n";

    return 0;
}