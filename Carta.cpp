#include "Carta.h"

// Construtor.
Carta::Carta(int forca) : forca(forca) {}

// Retorna a força da carta.
int Carta::getForca() const {
    return forca;
}

// Operador "menor que" para comparação de força entre cartas.
bool Carta::operator<(const Carta& other) const {
    return forca < other.forca;
}

// Operador "maior que" para comparação de força entre cartas.
bool Carta::operator>(const Carta& other) const {
    return forca > other.forca;
}

// Operador "igual a" para comparação de força entre cartas.
bool Carta::operator==(const Carta& other) const {
    return forca == other.forca;
}