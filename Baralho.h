#ifndef BARALHO_H
#define BARALHO_H

#include <vector>
#include <random>
#include "Carta.h"
#include "Jogador.h"

// Classe que representa o baralho de cartas do jogo.
class Baralho {
public:
    // Cria um novo baralho com as cartas do Truco.
    void criarBaralho();

    // Embaralha as cartas do baralho.
    void embaralhar();

    // Distribui as cartas para os jogadores.
    // Parâmetros:
    //   jogadores: Vetor de ponteiros para os jogadores que receberão as cartas.
    void distribuirCartas(std::vector<Jogador*>& jogadores);

    // Retorna o baralho atual.
    std::vector<Carta> getBaralho() const;

    // Retorna a carta "vira".
    Carta getVira() const;

private:
    std::vector<Carta> cartas; // Vetor que armazena as cartas do baralho.
    Carta vira; // Carta virada no início da rodada.
};

#endif // BARALHO_H