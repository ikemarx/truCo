#include <iostream>
#include "Game.h"

int main() {
    std::cout << "=== Bem-vindo ao Truco! ===\n";
    
    Game jogo;
    jogo.initializeGame();

    Team* vencedor = nullptr;
    int rodada = 1;

    while (!vencedor) {
        std::cout << "\n=== Rodada " << rodada << " ===\n";
        // Aqui seria a impressão do placar
        
        // Distribuir cartas
        // jogo.distributeCards();
        
        // Jogar rodada
        // Team* vencedorRodada = jogo.playRound();
        
        // Verificar vencedor
        vencedor = jogo.checkGameWinner();
        rodada++;
    }

    std::cout << "\n" << vencedor->getName() << " venceu o jogo!\n";

    return 0;
}
