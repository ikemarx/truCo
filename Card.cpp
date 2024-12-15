#include "Card.h"

Card::Card(int cardStrength) : strength(cardStrength) {}

int Card::getStrength() const {
    return strength;
}

bool Card::operator<(const Card& other) const {
    return strength < other.strength;
}

bool Card::operator>(const Card& other) const {
    return strength > other.strength;
}

bool Card::operator==(const Card& other) const {
    return strength == other.strength;
}
