#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include <vector>
#include "Jogador.h"

// Classe que representa uma equipe do jogo de Truco.
class Equipe {
private:
    std::string nome; // Nome da equipe.
    std::vector<Jogador*> jogadores; // Vetor de ponteiros para os jogadores da equipe.
    int pontos; // Pontuação da equipe na partida.
    int vitoriasRodada; // Número de rodadas vencidas pela equipe.

public:
    // Construtor.
    // Parâmetros:
    //   nome: Nome da equipe.
    Equipe(const std::string& nome);

    // Retorna o nome da equipe.
    std::string getNome() const;

    // Adiciona um jogador à equipe.
    // Parâmetros:
    //   jogador: Ponteiro para o jogador a ser adicionado.
    void adicionarJogador(Jogador* jogador);

    // Retorna os jogadores da equipe.
    const std::vector<Jogador*>& getJogadores() const;

    // Retorna a pontuação da equipe.
    int getPontos() const;

    // Adiciona pontos à equipe.
    // Parâmetros:
    //   valor: Quantidade de pontos a ser adicionada.
    void adicionarPontos(int valor);

    // Zera o contador de vitórias em rodadas.
    void zerarVitoriasRodada();

    // Incrementa o contador de vitórias em rodadas.
    void incrementarVitoriasRodada();

    // Retorna o número de vitórias em rodadas da equipe.
    int getVitoriasRodada() const;
};

#endif // EQUIPE_H