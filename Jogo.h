#ifndef JOGO_H
#define JOGO_H

#include <vector>
#include <memory>
#include "Equipe.h"
#include "Jogador.h"
#include "Baralho.h"
#include "Rodada.h"

// Classe principal que controla o fluxo do jogo de Truco.
class Jogo {
private:
    std::unique_ptr<Equipe> equipe1; // Primeira equipe.
    std::unique_ptr<Equipe> equipe2; // Segunda equipe.
    std::vector<Jogador*> jogadores; // Vetor com todos os jogadores (ordenados por times).
    Baralho baralho; // Baralho do jogo.
    int rodadaAtual; // Número da rodada atual.

public:
    // Construtor.
    Jogo();

    // Inicializa o jogo, definindo as equipes, jogadores e baralho.
    void inicializarJogo();

    // Inicia uma nova rodada.
    void jogarRodada();

    // Verifica se alguma equipe atingiu a pontuação para vencer o jogo.
    // Retorna:
    //   Ponteiro para a equipe vencedora (nullptr se o jogo ainda não acabou).
    Equipe* verificarVencedor();

    // Método getter para as equipes
    Equipe* getEquipe1();
    Equipe* getEquipe2();
};

#endif // JOGO_H