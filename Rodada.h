#ifndef RODADA_H
#define RODADA_H

#include <vector>
#include "Jogador.h"
#include "Carta.h"
#include "Equipe.h"

// Classe que representa uma rodada do jogo de Truco.
class Rodada {
private:
    int valor; // Valor da rodada (1, 3, 6, 9, 12).
    bool trucoFoiPedido; // Indica se o truco foi pedido nesta rodada.
    Equipe* equipeQuePediuTruco; // Ponteiro para a equipe que pediu o truco.
    std::vector<std::pair<Jogador*, Carta>> cartasJogadasNaRodada; // Cartas jogadas na rodada atual.
    int jogadorInicial;

public:
    // Construtor.
    // Parâmetros:
    //   valorInicial: Valor inicial da rodada.
    //   jogadorInicial: Índice do jogador que inicia a rodada.
    Rodada(int valorInicial, int jogadorInicial);

    // Inicia a rodada.
    // Parâmetros:
    //   jogadores: Vetor de ponteiros para os jogadores que participarão da rodada.
    // Retorna:
    //   Ponteiro para a equipe vencedora da rodada (nullptr se a rodada empatou).
    Equipe* iniciar(std::vector<Jogador*>& jogadores);

    // Determina o vencedor de uma volta da rodada.
    // Parâmetros:
    //   jogadas: Vetor de pares (Jogador, Carta) representando as jogadas da volta.
    // Retorna:
    //   Índice do jogador vencedor da volta.
    int determinarVencedorVolta(const std::vector<std::pair<Jogador*, Carta>>& jogadas);

    // Determina a equipe vencedora da rodada.
    // Retorna:
    //   Ponteiro para a equipe vencedora da rodada (nullptr se a rodada empatou).
    Equipe* determinarEquipeVencedora();
    // Getters
    bool getTrucoFoiPedido() const;
    Equipe* getEquipeQuePediuTruco() const;
    int getValor() const;

    // Aumenta o valor da rodada quando o truco é aceito.
    void aumentarValor();

private:
    // Reinicia o estado da rodada para a próxima.
    void resetarRodada();
};

#endif // RODADA_H