#include "Team.h"

Team::Team(const std::string& teamName) 
    : name(teamName), points(0), roundVictories(0) {}

std::string Team::getName() const {
    return name;
}

void Team::addPlayer(Player* player) {
    players.push_back(player);
}

const std::vector<Player*>& Team::getPlayers() const {
    return players;
}

int Team::getPoints() const {
    return points;
}

void Team::addPoints(int value) {
    points += value;
}

void Team::resetRoundVictories() {
    roundVictories = 0;
}

void Team::incrementRoundVictories() {
    roundVictories++;
}

int Team::getRoundVictories() const {
    return roundVictories;
}
