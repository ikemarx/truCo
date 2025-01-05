#ifndef CARTA_H
#define CARTA_H

// Classe que representa uma carta do jogo de Truco.
class Carta {
private:
    int forca; // Força da carta (1 a 10).

public:
    // Construtor.
    // Parâmetros:
    //   forca: Força da carta.
    Carta(int forca = 0);

    // Retorna a força da carta.
    int getForca() const;

    // Sobrecarga de operadores para comparação de cartas.
    bool operator<(const Carta& other) const;
    bool operator>(const Carta& other) const;
    bool operator==(const Carta& other) const;
};

#endif // CARTA_H