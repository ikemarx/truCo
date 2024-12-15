#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Game.h"

Game::Game() : 
    team1(std::make_unique<Team>("Nós")), 
    team2(std::make_unique<Team>("Eles")), 
    roundValue(1), 
    trucoCalled(false), 
    trucoCaller(nullptr),
    firstPlayerIndex(0) {}

void Game::createDeck() {
    // Criar 4 cópias de cada carta de 1 a 6
    for (int strength = 1; strength <= 6; ++strength) {
        for (int i = 0; i < 4; ++i) {
            deck.push_back(Card(strength));
        }
    }

    // Adicionar as manilhas (valores únicos)
    for (int strength = 7; strength <= 10; ++strength) {
        deck.push_back(Card(strength));
    }

    // Remover uma carta aleatória de 1 a 6
    std::vector<Card> removableCarts;
    std::copy_if(deck.begin(), deck.end(), std::back_inserter(removableCarts), 
        [](const Card& card) { return card.getStrength() >= 1 && card.getStrength() <= 6; });
    
    if (!removableCarts.empty()) {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> distribution(0, removableCarts.size() - 1);
        
        Card cardToRemove = removableCarts[distribution(generator)];
        auto it = std::find(deck.begin(), deck.end(), cardToRemove);
        if (it != deck.end()) {
            deck.erase(it);
        }
    }

    shuffleDeck();
}

void Game::shuffleDeck() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::shuffle(deck.begin(), deck.end(), generator);
}

void Game::distributeCards() {
    // Limpar mãos anteriores
    for (Player* player : players) {
        player->clearHand();
    }

    // Distribuir 3 cartas para cada jogador
    for (Player* player : players) {
        for (int i = 0; i < 3; ++i) {
            if (!deck.empty()) {
                player->addCardToHand(deck.back());
                deck.pop_back();
            }
        }
    }
}

void Game::initializeGame() {
    // Configuração das equipes (similar à versão Python)
    std::string teamName1, teamName2;
    std::string player1Name, player2Name, player3Name, player4Name;

    std::cout << "\n=== Configuração das Equipes ===\n";
    std::cout << "Nome da primeira equipe: ";
    std::getline(std::cin, teamName1);
    teamName1 = teamName1.empty() ? "Nós" : teamName1;

    std::cout << "Nome da segunda equipe: ";
    std::getline(std::cin, teamName2);
    teamName2 = teamName2.empty() ? "Eles" : teamName2;

    team1 = std::make_unique<Team>(teamName1);
    team2 = std::make_unique<Team>(teamName2);

    std::cout << "\n=== Jogadores da equipe " << team1->getName() << " ===\n";
    std::cout << "Nome do primeiro jogador: ";
    std::getline(std::cin, player1Name);
    player1Name = player1Name.empty() ? "João" : player1Name;

    std::cout << "Nome do segundo jogador: ";
    std::getline(std::cin, player2Name);
    player2Name = player2Name.empty() ? "Sérgio" : player2Name;

    std::cout << "\n=== Jogadores da equipe " << team2->getName() << " ===\n";
    std::cout << "Nome do primeiro jogador: ";
    std::getline(std::cin, player3Name);
    player3Name = player3Name.empty() ? "Paulo" : player3Name;

    std::cout << "Nome do segundo jogador: ";
    std::getline(std::cin, player4Name);
    player4Name = player4Name.empty() ? "Carlos" : player4Name;

    // Criar jogadores
    auto* player1 = new Player(player1Name, team1.get());
    auto* player2 = new Player(player2Name, team1.get());
    auto* player3 = new Player(player3Name, team2.get());
    auto* player4 = new Player(player4Name, team2.get());

    team1->addPlayer(player1);
    team1->addPlayer(player2);
    team2->addPlayer(player3);
    team2->addPlayer(player4);

    // Ordem de jogadores
    players = {player1, player3, player2, player4};

    // Escolher primeiro jogador aleatoriamente
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 3);
    firstPlayerIndex = distribution(generator);

    std::cout << "\n=== Times configurados ===\n";
    std::cout << "Equipe " << team1->getName() << ": " 
              << player1->getName() << " e " << player2->getName() << std::endl;
    std::cout << "Equipe " << team2->getName() << ": " 
              << player3->getName() << " e " << player4->getName() << std::endl;

    std::cout << "\n" << players[firstPlayerIndex]->getName() 
              << " vai começar jogando!\n";
    std::cout << "\nIniciando o jogo...\n";

    createDeck();
}

void Game::playRound() {
    // Implementação detalhada da rodada de jogo
    // Essa será uma tradução complexa do método Python
    // Incluirá lógica de jogar cartas, truco, etc.
    // Será implementada em próximas iterações
}

Team* Game::checkGameWinner() {
    if (team1->getPoints() >= 12) return team1.get();
    if (team2->getPoints() >= 12) return team2.get();
    return nullptr;
}

// Métodos restantes serão implementados de forma similar
