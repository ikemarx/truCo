#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include "Player.h"

class Team {
private:
    std::string name;
    std::vector<Player*> players;
    int points;
    int roundVictories;

public:
    // Construtor
    Team(const std::string& teamName);

    // Nome da equipe
    std::string getName() const;

    // Adicionar jogadores
    void addPlayer(Player* player);
    const std::vector<Player*>& getPlayers() const;

    // Gerenciamento de pontuação
    int getPoints() const;
    void addPoints(int value);
    void resetRoundVictories();
    void incrementRoundVictories();
    int getRoundVictories() const;
};

#endif // TEAM_H
