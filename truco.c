#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define CARDS_PER_HAND 3
#define NUM_SUITS 4
#define NUM_RANKS 10

// Enumerations for the suits and ranks of the cards
enum suit {SPADES, HEARTS, DIAMONDS, CLUBS};
enum rank {FOUR, FIVE, SIX, SEVEN, QUEEN, JACK, KING, ACE, TWO, THREE};

// Structure for a card, with fields for the suit and rank
struct card {
    enum suit suit;
    enum rank rank;
};

// Typedef for the card structure, to avoid repeating the struct keyword
typedef struct card card_t;

// Function prototypes
void shuffleDeck(card_t *deck, int size, card_t *hands, int numPlayers);
void printHands(card_t *hands, int numPlayers);
void printCard(card_t card);
void displayMenu(int *numPlayers, int *deckType);

int main() {
    int numPlayers, deckType, highest, current, whoMade = 0;
    int usScore = 0;
    int themScore = 0;
    bool gameOver = false;

    displayMenu(&numPlayers, &deckType);

    int deckSize;
    switch (deckType) {
        case 1:
            deckSize = NUM_SUITS * NUM_RANKS;
            break;
        case 2:
            deckSize = NUM_SUITS * (NUM_RANKS - 2);
            break;
        case 3:
            deckSize = NUM_SUITS * (NUM_RANKS - 3);
            break;
        default:
            printf("Invalid deck type\n");
            return 1;
    }

    card_t *deck = (card_t *)malloc(deckSize * sizeof(card_t));
    card_t *hands = (card_t *)malloc(CARDS_PER_HAND * numPlayers * sizeof(card_t));

    if (deck == NULL || hands == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (!gameOver) {
        highest = 0;
        shuffleDeck(deck, deckSize, hands, numPlayers);
        printHands(hands, numPlayers);

        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d: ", i + 1);
            scanf("%d", &current);
            if (current > highest) {
                highest = current;
                whoMade = i + 1;
            } else if (current == highest) 
        }
        if (whoMade % 2 == 1) {
            
        }

        // Update the scores and check if the game is over
    }

    free(deck);
    free(hands);
    return 0;
}

void shuffleDeck(card_t *deck, int size, card_t *hands, int numPlayers) {
    // Initialize the deck with all the possible cards
    for (int i = 0; i < size; i++) {
        deck[i].suit = i / NUM_RANKS;
        deck[i].rank = i % NUM_RANKS;
    }

    srand(time(NULL));

    // Shuffle the deck using the Fisher-Yates algorithm
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        card_t temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Copy the first cards from the deck to the hands
    for (int i = 0; i < CARDS_PER_HAND * numPlayers; i++) {
        hands[i] = deck[i];
    }
}

void printHands(card_t *hands, int numPlayers) {
    for (int i = 0; i < CARDS_PER_HAND * numPlayers; i++) {
        if ((i % CARDS_PER_HAND) == 0)
            printf("Hand:\n");
        printCard(hands[i]);
    }
}

void printCard(card_t card) {
    // Print the rank of the card
    switch (card.rank) {
        case FOUR:
            printf("4 of ");
            break;
        case FIVE:
            printf("5 of ");
            break;
        case SIX:
            printf("6 of ");
            break;
        case SEVEN:
            printf("7 of ");
            break;
        case QUEEN:
            printf("Q of ");
            break;
        case JACK:
            printf("J of ");
            break;
        case KING:
            printf("K of ");
            break;
        case ACE:
            printf("A of ");
            break;
        case TWO:
            printf("2 of ");
            break;
        case THREE:
            printf("3 of ");
            break;
    }

    // Print the suit of the card
    switch (card.suit) {
        case SPADES:
            printf("spades\n");
            break;
        case HEARTS:
            printf("hearts\n");
            break;
        case DIAMONDS:
            printf("diamonds\n");
            break;
        case CLUBS:
            printf("clubs\n");
            break;
    }
}

void displayMenu(int *numPlayers, int *deckType) {
    int languageChoice;

    printf("Select language:\n");
    printf("1. English\n");
    printf("2. Portuguese\n");
    printf("Choose: ");
    scanf("%d", &languageChoice);

    if (languageChoice == 1) {
        printf("\tTruco Paulista in C\n");
        // Validate the user input for the number of players
        do {
            printf("How many players?\n");
            printf("Choose 2, 4, or 6: ");
            scanf("%d", numPlayers);
        } while (*numPlayers != 2 && *numPlayers != 4 && *numPlayers != 6);
        // Validate the user input for the deck type
        do {
            printf("Which deck type?\n");
            printf("1. Dirty deck\n");
            printf("2. Clean deck\n");
            printf("3. Clean deck without 4\n");
            printf("Choose: ");
            scanf("%d", deckType);
        } while (*deckType < 1 || *deckType > 3);
    } else {
        printf("\tTruco Paulista em C\n");
        // Validate the user input for the number of players
        do {
            printf("Quantos jogadores?\n");
            printf("Escolha 2, 4, ou 6: ");
            scanf("%d", numPlayers);
        } while (*numPlayers != 2 && *numPlayers != 4 && *numPlayers != 6);
        // Validate the user input for the deck type
        do {
            printf("Qual modalidade?\n");
            printf("1. Baralho sujo\n");
            printf("2. Baralho limpo\n");
            printf("3. Baralho limpo sem o 4\n");
            printf("Escolha: ");
            scanf("%d", deckType);
        } while (*deckType < 1 || *deckType > 3);
    }
}