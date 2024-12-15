#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Team; // Forward declaration

class Player {
private:
    std::string name;
    Team* team;
    std::vector<Card> hand;
    std::vector<Card> playedCards;

public:
    // Construtor
    Player(const std::string& playerName, Team* playerTeam);

    // Nome do jogador
    std::string getName() const;

    // Equipe do jogador
    Team* getTeam();

    // Manipulação da mão de cartas
    void showHand() const;
    void addCardToHand(const Card& card);
    Card playCard(int index);
    bool hasCardsInHand() const;
    const std::vector<Card>& getHand() const;
    void clearHand();
};

#endif // PLAYER_H
