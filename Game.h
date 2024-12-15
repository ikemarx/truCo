#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <memory>
#include "Player.h"
#include "Team.h"
#include "Card.h"

class Game {
private:
    std::vector<Card> deck;
    std::unique_ptr<Team> team1;
    std::unique_ptr<Team> team2;
    std::vector<Player*> players;
    
    int roundValue;
    bool trucoCalled;
    Team* trucoCaller;
    int firstPlayerIndex;
    std::vector<Card> playedCards;

    // Métodos privados de suporte
    void createDeck();
    void shuffleDeck();
    void distributeCards();
    Team* determineRoundWinner();
    void handleTrucoRequest(Player* requestingPlayer);

public:
    Game();
    void initializeGame();
    void playRound();
    Team* checkGameWinner();
    
    // Decisões de truco
    int requestTrucoDecision(Player* currentPlayer, Player* nextPlayer);
    void increaseTrucoValue(Team* requestingTeam);
    void runTruco(Team* retreatingTeam);
};

#endif // GAME_H
