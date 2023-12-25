#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <Carta.h>


using namespace std;

vector<Carta*>* inicializarBaralho();
void embaralhar(vector<Carta*>* baralho);

void jogar() {
    Jogador* jogador1 = new Jogador();
    Jogador* jogador2 = new Jogador();
    Jogador* jogador3 = new Jogador();
    Jogador* jogador4 = new Jogador();
    vector<Carta*>* baralho = inicializarBaralho();
    embaralhar(baralho);
    darCartas(baralho, jogador1, jogador2, jogador3, jogador4);
}

vector<Carta*>* inicializarBaralho() {
    vector<Carta*>* baralho;
    int naipe[] = {1, 2, 3, 4};
    int valor[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 7; ++j) {
            Carta* carta = new Carta(valor[j], naipe[i]);
            baralho->push_back(carta);
            delete carta;
        }
    }
    return baralho;
}

void embaralhar(vector<Carta*>* baralho) {
    srand(static_cast<unsigned>(time(0)));
    random_shuffle(baralho->begin(), baralho->end());
}