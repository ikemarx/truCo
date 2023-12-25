#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo as constantes do jogo
#define NUM_CARTAS 40 // Número de cartas no baralho
#define NUM_JOGADORES 4 // Número de jogadores na partida
#define NUM_CARTAS_MAO 3 // Número de cartas na mão de cada jogador
#define NUM_PONTOS 12 // Número de pontos para ganhar a partida
#define NUM_NAIPES 4 // Número de naipes das cartas
#define NUM_NUMEROS 10 // Número de números das cartas

// Definindo as estruturas de dados
typedef struct carta {
    int numero; // Número da carta (4 a 7, Q, J, K, A, 2, 3)
    int naipe; // Naipe da carta (0 = ouros, 1 = espadas, 2 = copas, 3 = paus)
    int manilha; // Indica se a carta é manilha (0 = não, 1 = sim)
    int valor; // Valor da carta na ordem de força (4 a 14, sendo 14 a manilha mais forte)
} Carta;

typedef struct jogador {
    Carta mao[NUM_CARTAS_MAO]; // Cartas na mão do jogador
    int pontos; // Pontos do jogador na partida
    int equipe; // Equipe do jogador (0 ou 1)
    int vez; // Indica se é a vez do jogador (0 = não, 1 = sim)
    int truco; // Indica se o jogador pode pedir truco (0 = não, 1 = sim)
} Jogador;

typedef struct mesa {
    Carta vira; // Carta que define as manilhas
    Carta rodada[NUM_JOGADORES]; // Cartas jogadas na rodada
    int valor_mao; // Valor da mão em pontos
    int rodada_atual; // Número da rodada atual (1, 2 ou 3)
    int mao_atual; // Número da mão atual
    int equipe_rodada; // Equipe que ganhou a rodada anterior
    int equipe_mao; // Equipe que ganhou a mão anterior
} Mesa;

// Protótipos das funções
void embaralhar(Carta baralho[NUM_CARTAS]); // Embaralha as cartas
void distribuir(Carta baralho[NUM_CARTAS], Jogador jogadores[NUM_JOGADORES]); // Distribui as cartas para os jogadores
void definir_vira(Carta baralho[NUM_CARTAS], Mesa *mesa); // Define a carta que será a vira
void definir_manilhas(Jogador jogadores[NUM_JOGADORES], Mesa *mesa); // Define as manilhas de acordo com a vira
void ordenar_mao(Jogador *jogador); // Ordena a mão do jogador de acordo com o valor das cartas
void mostrar_mao(Jogador jogador); // Mostra a mão do jogador na tela
void jogar_carta(Jogador *jogador, Mesa *mesa, int indice); // Joga uma carta na mesa
int comparar_cartas(Carta c1, Carta c2); // Compara duas cartas e retorna 1 se a primeira é maior, -1 se a segunda é maior e 0 se são iguais
int verificar_vencedor_rodada(Mesa mesa); // Verifica qual equipe venceu a rodada e retorna 0 ou 1
int verificar_vencedor_mao(Mesa mesa); // Verifica qual equipe venceu a mão e retorna 0 ou 1
int verificar_vencedor_partida(Jogador jogadores[NUM_JOGADORES]); // Verifica se alguma equipe venceu a partida e retorna 0 ou 1
void atualizar_pontos(Jogador jogadores[NUM_JOGADORES], Mesa *mesa, int equipe); // Atualiza os pontos da equipe vencedora da mão
void limpar_rodada(Mesa *mesa); // Limpa as cartas jogadas na rodada
void limpar_mao(Jogador jogadores[NUM_JOGADORES], Mesa *mesa); // Limpa as cartas na mão dos jogadores
void limpar_partida(Jogador jogadores[NUM_JOGADORES], Mesa *mesa); // Limpa os pontos e as cartas dos jogadores e da mesa
void pedir_truco(Jogador *jogador, Mesa *mesa); // Pede truco e aumenta o valor da mão
void aceitar_truco(Jogador *jogador, Mesa *mesa); // Aceita o truco e continua a mão
void recusar_truco(Jogador *jogador, Mesa *mesa); // Recusa o truco e perde a mão
void mostrar_placar(Jogador jogadores[NUM_JOGADORES]); // Mostra o placar da partida na tela
void mostrar_rodada(Mesa mesa); // Mostra as cartas jogadas na rodada na tela
void mostrar_vira(Mesa mesa); // Mostra a carta que é a vira na tela
void mostrar_mensagem(char *mensagem); // Mostra uma mensagem na tela
void pausar(); // Pausa o programa até o usuário pressionar uma tecla
int ler_opcao(int min, int max); // Lê uma opção do usuário entre um valor mínimo e máximo

// Função principal
int main() {
    // Declarando as variáveis
    Carta baralho[NUM_CARTAS]; // Baralho de cartas
    Jogador jogadores[NUM_JOGADORES]; // Jogadores da partida
    Mesa mesa; // Mesa da partida
    int i, j, k; // Variáveis auxiliares
    int opcao; // Opção escolhida pelo usuário
    int equipe; // Equipe vencedora da partida
    int rodada; // Equipe vencedora da rodada
    int mao; // Equipe vencedora da mão
    int partida; // Indica se a partida terminou (0 = não, 1 = sim)
    int truco; // Indica se houve pedido de truco (0 = não, 1 = sim)
    int aceito; // Indica se o truco foi aceito (0 = não, 1 = sim)
    char mensagem[100]; // Mensagem a ser mostrada na tela

    // Inicializando o gerador de números aleatórios
    srand(time(NULL));

    // Inicializando o baralho de cartas
    for (i = 0; i < NUM_NAIPES; i++) {
        for (j = 0; j < NUM_NUMEROS; j++) {
            k = i * NUM_NUMEROS + j; // Índice da carta no baralho
            baralho[k].numero = j + 4; // Número da carta (4 a 7, Q, J, K, A, 2, 3)
            baralho[k].naipe = i; // Naipe da carta (0 = ouros, 1 = espadas, 2 = copas, 3 = paus)
            baralho[k].manilha = 0; // Indica que a carta não é manilha
            baralho[k].valor = j + 4; // Valor da carta na ordem de força (4 a 14, sendo 14 a manilha mais forte)
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
        embaralhar(baralho);

