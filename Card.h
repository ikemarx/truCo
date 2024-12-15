#ifndef CARD_H
#define CARD_H

class Card {
private:
    int strength; // Força da carta no truco

public:
    // Construtor
    Card(int cardStrength = 0);

    // Getter para força da carta
    int getStrength() const;

    // Sobrecarga de operadores para comparação de cartas
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator==(const Card& other) const;
};

#endif // CARD_H
