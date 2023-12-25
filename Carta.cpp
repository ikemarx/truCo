#include "Carta.h"

Carta::Carta(int valor, int naipe) : valor(valor), naipe(naipe) {}

Carta::~Carta() {}

int Carta::getValor() {
    return valor;
}


int Carta::getNaipe() {
    return naipe;
}

void Carta::setValor(int valor) {
    this->valor = valor;
}

int Carta::setNaipe() {
    this->naipe = naipe;
}