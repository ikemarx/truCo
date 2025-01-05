#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Jogo.h"

// Construtor.
Jogo::Jogo() : rodadaAtual(1) {
    baralho.criarBaralho(); // Cria o baralho no início do jogo.
}

// Inicializa o jogo.
void Jogo::inicializarJogo() {
    // Configuração das equipes.
    std::string nomeEquipe1, nomeEquipe2;
    std::string nomeJogador1, nomeJogador2, nomeJogador3, nomeJogador4;

    std::cout << "\n=== Configuração das Equipes ===\n";
    std::cout << "Nome da primeira equipe: ";
    std::getline(std::cin, nomeEquipe1);
    nomeEquipe1 = nomeEquipe1.empty() ? "Nós" : nomeEquipe1;

    std::cout << "Nome da segunda equipe: ";
    std::getline(std::cin, nomeEquipe2);
    nomeEquipe2 = nomeEquipe2.empty() ? "Eles" : nomeEquipe2;

    equipe1 = std::make_unique<Equipe>(nomeEquipe1);
    equipe2 = std::make_unique<Equipe>(nomeEquipe2);

    std::cout << "\n=== Jogadores da equipe " << equipe1->getNome() << " ===\n";
    std::cout << "Nome do primeiro jogador: ";
    std::getline(std::cin, nomeJogador1);
    nomeJogador1 = nomeJogador1.empty() ? "João" : nomeJogador1;

    std::cout << "Nome do segundo jogador: ";
    std::getline(std::cin, nomeJogador2);
    nomeJogador2 = nomeJogador2.empty() ? "Sérgio" : nomeJogador2;

    std::cout << "\n=== Jogadores da equipe " << equipe2->getNome() << " ===\n";
    std::cout << "Nome do primeiro jogador: ";
    std::getline(std::cin, nomeJogador3);
    nomeJogador3 = nomeJogador3.empty() ? "Paulo" : nomeJogador3;

    std::cout << "Nome do segundo jogador: ";
    std::getline(std::cin, nomeJogador4);
    nomeJogador4 = nomeJogador4.empty() ? "Carlos" : nomeJogador4;

    // Cria os jogadores.
    Jogador* jogador1 = new Jogador(nomeJogador1, equipe1.get());
    Jogador* jogador2 = new Jogador(nomeJogador2, equipe1.get());
    Jogador* jogador3 = new Jogador(nomeJogador3, equipe2.get());
    Jogador* jogador4 = new Jogador(nomeJogador4, equipe2.get());

    // Adiciona os jogadores às equipes.
    equipe1->adicionarJogador(jogador1);
    equipe1->adicionarJogador(jogador2);
    equipe2->adicionarJogador(jogador3);
    equipe2->adicionarJogador(jogador4);

    // Define a ordem dos jogadores.
    jogadores = {jogador1, jogador3, jogador2, jogador4};

    // Escolhe o primeiro jogador aleatoriamente.
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gerador(seed);
    std::uniform_int_distribution<int> distribuicao(0, 3);
    int indicePrimeiroJogador = distribuicao(gerador);

    // Reordena o vetor de jogadores para que o jogador escolhido seja o primeiro.
    std::rotate(jogadores.begin(), jogadores.begin() + indicePrimeiroJogador, jogadores.end());

    std::cout << "\n=== Times configurados ===\n";
    std::cout << "Equipe " << equipe1->getNome() << ": "
              << jogador1->getNome() << " e " << jogador2->getNome() << std::endl;
    std::cout << "Equipe " << equipe2->getNome() << ": "
              << jogador3->getNome() << " e " << jogador4->getNome() << std::endl;

    std::cout << "\n" << jogadores[0]->getNome()
              << " vai começar jogando!\n";
    std::cout << "\nIniciando o jogo...\n";
}

// Inicia uma nova rodada.
void Jogo::jogarRodada() {
    baralho.distribuirCartas(jogadores);
    // Cria uma nova rodada, passando o valor inicial e o índice do jogador que inicia.
    Rodada rodada(1, 0);

    // Inicia a rodada e obtém a equipe vencedora.
    Equipe* vencedora = rodada.iniciar(jogadores);

    // Atualiza a pontuação da equipe vencedora.
    if (vencedora) {
        vencedora->adicionarPontos(rodada.getValor());
    }

    rodadaAtual++;
}

// Verifica se alguma equipe atingiu a pontuação para vencer o jogo.
Equipe* Jogo::verificarVencedor() {
    if (equipe1->getPontos() >= 12) {
        return equipe1.get();
    } else if (equipe2->getPontos() >= 12) {
        return equipe2.get();
    } else {
        return nullptr;
    }
}

// getters
Equipe* Jogo::getEquipe1() {
    return equipe1.get();
}

Equipe* Jogo::getEquipe2() {
    return equipe2.get();
}