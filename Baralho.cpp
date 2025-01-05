#include "Baralho.h"
#include <chrono>
#include <algorithm>

// Cria um baralho com as cartas do Truco.
void Baralho::criarBaralho() {
    // Cria 4 cópias de cada carta de 1 a 6.
    for (int forca = 1; forca <= 6; ++forca) {
        for (int i = 0; i < 4; ++i) {
            cartas.push_back(Carta(forca));
        }
    }

    // Adiciona as manilhas (valores únicos de 7 a 10).
    for (int forca = 7; forca <= 10; ++forca) {
        cartas.push_back(Carta(forca));
    }

    // Remove uma carta aleatória de 1 a 6 e a define como a "vira".
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gerador(seed);
    std::uniform_int_distribution<int> distribuicao(0, 5);

    int forcaCartaRemovida = distribuicao(gerador) + 1;

    auto it = std::find_if(cartas.begin(), cartas.end(), [&](const Carta& carta) {
        return carta.getForca() == forcaCartaRemovida;
    });

    if (it != cartas.end()) {
        vira = *it;
        cartas.erase(it);
    }

    embaralhar();
}

// Embaralha as cartas do baralho.
void Baralho::embaralhar() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gerador(seed);
    std::shuffle(cartas.begin(), cartas.end(), gerador);
}

// Distribui as cartas para os jogadores.
void Baralho::distribuirCartas(std::vector<Jogador*>& jogadores) {
    // Limpa as mãos dos jogadores.
    for (Jogador* jogador : jogadores) {
        jogador->limparMao();
    }

    // Distribui 3 cartas para cada jogador.
    for (Jogador* jogador : jogadores) {
        for (int i = 0; i < 3; ++i) {
            if (!cartas.empty()) {
                jogador->adicionarCarta(cartas.back());
                cartas.pop_back();
            }
        }
    }
}

// Retorna o baralho atual.
std::vector<Carta> Baralho::getBaralho() const {
    return cartas;
}

// Retorna a carta "vira".
Carta Baralho::getVira() const {
    return vira;
}