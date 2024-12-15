#include "truco.h"

int main() {
    // Declarando as variáveis
    Carta baralho[NUM_CARTAS_SUJO]; // Baralho de cartas
    Jogador jogadores[NUM_JOGADORES]; // Jogadores da partida
    Mesa mesa; // Mesa da partida
    int i, j, k; // Variáveis auxiliares
    int opcao = 0; // Opção escolhida pelo usuário
    int equipe; // Equipe vencedora da partida
    int rodada; // Equipe vencedora da rodada
    int mao; // Equipe vencedora da mão
    int partida; // Indica se a partida terminou (0 = não, 1 = sim)
    int truco; // Indica se houve pedido de truco (0 = não, 1 = sim)
    int aceito; // Indica se o truco foi aceito (0 = não, 1 = sim)
    int num_numeros;
    int num_cartas;
    char mensagem[100]; // Mensagem a ser mostrada na tela

    // Inicializando o gerador de números aleatórios
    srand(time(NULL));

    //Menu inicial
    do {
        printf("\tTruco Paulista em C\n");
        printf("Com que baralho deseja jogar?\n");
        printf("1. Baralho Sujo\n2. Baralho Limpo\nEscolha: ");
        scanf("%d", &opcao);
    } while (opcao != 1 && opcao != 2);

    // Inicializando o baralho de cartas
    if (opcao == 1) {
        num_numeros = NUM_NUMEROS_SUJO;
        num_cartas = NUM_CARTAS_SUJO;
    }
    if (opcao == 2) {
        num_numeros = NUM_NUMEROS_LIMPO;
        num_cartas = NUM_CARTAS_LIMPO;
    }
    for (i = 0; i < NUM_NAIPES; i++) {
        for (j = 0; j < num_numeros; j++) {
            k = i * num_numeros + j; // Índice da carta no baralho
            baralho[k].numero = j; // Número da carta (4 a 7, Q, J, K, A, 2, 3)
            baralho[k].naipe = i; // Naipe da carta (0 = ouros, 1 = espadas, 2 = copas, 3 = paus)
            baralho[k].manilha = 0; // Indica que a carta não é manilha
            baralho[k].valor = j; // Valor da carta na ordem de força (0 a 9, sendo 9 a manilha mais fraca)
        }
    }

    // Inicializando os jogadores da partida
    for (i = 0; i < NUM_JOGADORES; i++) {
        jogadores[i].pontos = 0; // Pontos do jogador na partida
        jogadores[i].equipe = i % 2; // Equipe do jogador (0 ou 1)
        jogadores[i].vez = 0; // Indica que não é a vez do jogador
        jogadores[i].truco = 0; // Indica que o jogador não pode pedir truco
    }

    // Inicializando a mesa da partida
    mesa.valor_mao = 1; // Valor da mão em pontos
    mesa.rodada_atual = 1; // Número da rodada atual
    mesa.mao_atual = 1; // Número da mão atual
    mesa.equipe_rodada = -1; // Equipe que ganhou a rodada anterior
    mesa.equipe_mao = -1; // Equipe que ganhou a mão anterior

    // Iniciando a partida
    partida = 0; // Indica que a partida não terminou
    while (!partida) {
        // Embaralhando as cartas
        embaralhar(baralho, num_cartas);
    }
}