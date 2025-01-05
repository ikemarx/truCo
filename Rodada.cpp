#include "Rodada.h"
#include <iostream>
#include <limits>

// Construtor.
Rodada::Rodada(int valorInicial, int jogadorInicial)
    : valor(valorInicial), trucoFoiPedido(false), equipeQuePediuTruco(nullptr), jogadorInicial(jogadorInicial) {}

// Inicia a rodada.
Equipe* Rodada::iniciar(std::vector<Jogador*>& jogadores) {
    std::cout << "\n=== Rodada valendo " << valor << " ===\n";

    // Determina a ordem dos jogadores para esta rodada.
    std::vector<Jogador*> jogadoresDaRodada;
    for (int i = 0; i < jogadores.size(); ++i) {
        jogadoresDaRodada.push_back(jogadores[(jogadorInicial + i) % jogadores.size()]);
    }

    // Limpa as cartas jogadas na rodada anterior.
    cartasJogadasNaRodada.clear();

    // Loop de jogadas (3 voltas).
    for (int volta = 0; volta < 3; ++volta) {
        std::cout << "\n-- Volta " << volta + 1 << " --\n";
        std::vector<std::pair<Jogador*, Carta>> jogadasDaVolta;

        for (int i = 0; i < jogadoresDaRodada.size(); ++i) {
            Jogador* jogadorAtual = jogadoresDaRodada[i];
            jogadorAtual->mostrarMao();

            int indiceCarta;
            do {
                std::cout << jogadorAtual->getNome() << ", escolha uma carta (1-" << jogadorAtual->getMao().size() << "): ";
                if (std::cin >> indiceCarta && indiceCarta >= 1 && indiceCarta <= jogadorAtual->getMao().size()) {
                    break;
                } else {
                    std::cout << "Escolha inválida. Tente novamente.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (true);

            Carta cartaJogada = jogadorAtual->jogarCarta(indiceCarta);
            jogadasDaVolta.push_back({jogadorAtual, cartaJogada});
            std::cout << jogadorAtual->getNome() << " jogou a carta de força " << cartaJogada.getForca() << '\n';

            // Lógica do Truco (simplificada, adicionar lógica real aqui).
            if (volta < 2) { // Só permite pedir truco nas duas primeiras voltas.
                // Pergunta ao jogador se quer pedir truco.
                if (/* Condição para verificar se o jogador quer pedir truco */) {
                   std::cout << jogadorAtual->getNome() << ", quer pedir truco? (s/n): ";
                    char resposta;
                    std::cin >> resposta;
                    if (resposta == 's' || resposta == 'S') {
                        //  handleTrucoRequest(jogadorAtual);
                    }
                }
            }
        }

        // Determina o vencedor da volta.
        int indiceVencedorVolta = determinarVencedorVolta(jogadasDaVolta);
        std::cout << "\nVencedor da volta: " << jogadasDaVolta[indiceVencedorVolta].first->getNome() << '\n';

        // Atualiza o jogador inicial para a próxima volta.
        jogadorInicial = (jogadorInicial + indiceVencedorVolta) % jogadores.size();

        // Adiciona as cartas da volta atual às cartas jogadas na rodada.
        for (const auto& jogada : jogadasDaVolta) {
            cartasJogadasNaRodada.push_back(jogada);
        }
    }

    // Determina a equipe vencedora da rodada.
    Equipe* equipeVencedora = determinarEquipeVencedora();
    if (equipeVencedora) {
        equipeVencedora->adicionarPontos(valor);
        std::cout << "\n" << equipeVencedora->getNome() << " ganhou a rodada!\n";
    } else {
        std::cout << "\nA rodada empatou!\n";
    }

    // Reseta o estado da rodada para a próxima.
    resetarRodada();

    return equipeVencedora;
}

// Determina o vencedor de uma volta da rodada.
int Rodada::determinarVencedorVolta(const std::vector<std::pair<Jogador*, Carta>>& jogadas) {
    // Lógica simplificada para determinar o vencedor da volta.
    // (Aqui você precisa implementar a lógica real do Truco para comparar as cartas).
    int indiceVencedor = 0;
    for (int i = 1; i < jogadas.size(); ++i) {
        if (jogadas[i].second.getForca() > jogadas[indiceVencedor].second.getForca()) {
            indiceVencedor = i;
        }
    }
    return indiceVencedor;
}

// Determina a equipe vencedora da rodada.
Equipe* Rodada::determinarEquipeVencedora() {
    // Lógica simplificada para determinar a equipe vencedora da rodada.
    // (Aqui você precisa implementar a lógica real do Truco para contar as vitórias de cada equipe nas voltas).
    
    // Conta as vitórias de cada equipe nas voltas.
    int vitoriasEquipe1 = 0;
    int vitoriasEquipe2 = 0;
    // Equipe do jogador 1 é a equipe 1 e a do jogador 2 é a equipe 2
    for (const auto& jogada : cartasJogadasNaRodada) {
      if (jogada.first->getEquipe() == jogada.first->getEquipe()->getJogadores()[0]->getEquipe()) {
        vitoriasEquipe1++;
      } else {
        vitoriasEquipe2++;
      }
    }

    // Verifica qual equipe venceu mais voltas.
    if (vitoriasEquipe1 > vitoriasEquipe2) {
        return cartasJogadasNaRodada[0].first->getEquipe();
    } else if (vitoriasEquipe2 > vitoriasEquipe1) {
        return cartasJogadasNaRodada[1].first->getEquipe();
    } else {
        return nullptr; // Empate.
    }
}

bool Rodada::getTrucoFoiPedido() const {
    return trucoFoiPedido;
}

Equipe* Rodada::getEquipeQuePediuTruco() const {
    return equipeQuePediuTruco;
}

int Rodada::getValor() const {
    return valor;
}

void Rodada::aumentarValor() {
    if (valor == 1) {
        valor = 3;
    } else if (valor == 3) {
        valor = 6;
    } else if (valor == 6) {
        valor = 9;
    } else if (valor == 9) {
        valor = 12;
    }
}

void Rodada::resetarRodada() {
    valor = 1;
    trucoFoiPedido = false;
    equipeQuePediuTruco = nullptr;
    cartasJogadasNaRodada.clear();
}