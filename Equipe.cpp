#include "Equipe.h"

// Construtor.
Equipe::Equipe(const std::string& nome) : nome(nome), pontos(0), vitoriasRodada(0) {}

// Retorna o nome da equipe.
std::string Equipe::getNome() const {
    return nome;
}

// Adiciona um jogador à equipe.
void Equipe::adicionarJogador(Jogador* jogador) {
    jogadores.push_back(jogador);
}

// Retorna os jogadores da equipe.
const std::vector<Jogador*>& Equipe::getJogadores() const {
    return jogadores;
}

// Retorna a pontuação da equipe.
int Equipe::getPontos() const {
    return pontos;
}

// Adiciona pontos à equipe.
void Equipe::adicionarPontos(int valor) {
    pontos += valor;
}

// Zera o contador de vitórias em rodadas.
void Equipe::zerarVitoriasRodada() {
    vitoriasRodada = 0;
}

// Incrementa o contador de vitórias em rodadas.
void Equipe::incrementarVitoriasRodada() {
    vitoriasRodada++;
}

// Retorna o número de vitórias em rodadas da equipe.
int Equipe::getVitoriasRodada() const {
    return vitoriasRodada;
}