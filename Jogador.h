#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include "Carta.h"
#include "Equipe.h"

// Classe que representa um jogador do jogo de Truco.
class Jogador {
private:
    std::string nome; // Nome do jogador.
    Equipe* equipe; // Ponteiro para a equipe à qual o jogador pertence.
    std::vector<Carta> mao; // Cartas na mão do jogador.
    std::vector<Carta> cartasJogadas; // Cartas já jogadas pelo jogador.

public:
    // Construtor.
    // Parâmetros:
    //   nome: Nome do jogador.
    //   equipe: Ponteiro para a equipe do jogador.
    Jogador(const std::string& nome, Equipe* equipe);

    // Retorna o nome do jogador.
    std::string getNome() const;

    // Retorna a equipe do jogador.
    Equipe* getEquipe();

    // Mostra as cartas na mão do jogador.
    void mostrarMao() const;

    // Adiciona uma carta à mão do jogador.
    // Parâmetros:
    //   carta: Carta a ser adicionada.
    void adicionarCarta(const Carta& carta);

    // Joga uma carta da mão do jogador.
    // Parâmetros:
    //   indice: Índice da carta na mão a ser jogada.
    // Retorna:
    //   A carta jogada.
    Carta jogarCarta(int indice);

    // Verifica se o jogador ainda tem cartas na mão.
    bool temCartasNaMao() const;

    // Retorna a mão do jogador (cartas que ele ainda não jogou).
    const std::vector<Carta>& getMao() const;

    // Limpa a mão do jogador e as cartas jogadas.
    void limparMao();
};

#endif // JOGADOR_H