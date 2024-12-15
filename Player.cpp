#include <iostream>
#include "Player.h"
#include "Team.h"

Player::Player(const std::string& playerName, Team* playerTeam) 
    : name(playerName), team(playerTeam) {}

std::string Player::getName() const {
    return name;
}

Team* Player::getTeam() {
    return team;
}

void Player::showHand() const {
    std::cout << "\nCartas de " << name << ":\n";
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << i + 1 << ". Carta com força " << hand[i].getStrength() << std::endl;
    }
}

void Player::addCardToHand(const Card& card) {
    hand.push_back(card);
}

Card Player::playCard(int index) {
    if (index < 1 || index > static_cast<int>(hand.size())) {
        throw std::out_of_range("Índice de carta inválido");
    }
    
    Card playedCard = hand[index - 1];
    hand.erase(hand.begin() + index - 1);
    playedCards.push_back(playedCard);
    
    return playedCard;
}

bool Player::hasCardsInHand() const {
    return !hand.empty();
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}

void Player::clearHand() {
    hand.clear();
    playedCards.clear();
}
