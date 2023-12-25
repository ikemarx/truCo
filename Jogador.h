#include "Carta.h"

class Jogador {
private:
    int posicao;
    Carta* cartas[3];
public:
    Jogador();
    ~Jogador();
    int getPosicao();
    void setPosicao(int posicao);
};