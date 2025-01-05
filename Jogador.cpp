#include <iostream>
#include "Jogador.h"

// Construtor.
Jogador::Jogador(const std::string& nome, Equipe* equipe)
    : nome(nome), equipe(equipe) {}

// Retorna o nome do jogador.
std::string Jogador::getNome() const {
    return nome;
}

// Retorna a equipe do jogador.
Equipe* Jogador::getEquipe() {
    return equipe;
}

// Mostra as cartas na mão do jogador.
void Jogador::mostrarMao() const {
    std::cout << "\nCartas de " << nome << ":\n";
    for (size_t i = 0; i < mao.size(); ++i) {
        std::cout << i + 1 << ". Carta com força " << mao[i].getForca() << std::endl;
    }
}

// Adiciona uma carta à mão do jogador.
void Jogador::adicionarCarta(const Carta& carta) {
    mao.push_back(carta);
}

// Joga uma carta da mão do jogador.
Carta Jogador::jogarCarta(int indice) {
    if (indice < 1 || indice > static_cast<int>(mao.size())) {
        throw std::out_of_range("Índice de carta inválido");
    }

    Carta cartaJogada = mao[indice - 1];
    mao.erase(mao.begin() + indice - 1);
    cartasJogadas.push_back(cartaJogada);

    return cartaJogada;
}

// Verifica se o jogador ainda tem cartas na mão.
bool Jogador::temCartasNaMao() const {
    return !mao.empty();
}

// Retorna a mão do jogador (cartas que ele ainda não jogou).
const std::vector<Carta>& Jogador::getMao() const {
    return mao;
}

// Limpa a mão do jogador e as cartas jogadas.
void Jogador::limparMao() {
    mao.clear();
    cartasJogadas.clear();
}