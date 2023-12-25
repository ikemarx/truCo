#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embaralhar(int baralho[], int tamanho, int maos[], int modo) {
    for (int i = 0; i < tamanho; i++) {
        baralho[i] = i;
    }
    
    srand(time(NULL));
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Trocar elementos de posição
        int temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
    
    for (int i = 0; i < 3 * modo; i++) {
        maos[i] = baralho[i];
    }
    
    for (int i = 0; i < 3 * modo; i++) {
        if (i % 3 == 0) printf("Mao:\n");
        printf("%d\n", maos[i]);
    }
}

int main() {
    int modo, modalidade, tamanho, *maos, *baralho, maior, atual;
    int nos = 0;
    int eles = 0;
    int rodada = 0;
    int truco = 1;
    
    printf("\tTruco Paulista em C\n");
    printf("Quantos jogadores?\n");
    printf("Escolha 2, 4, ou 6: ");
    scanf("%d", &modo);
    printf("Qual modalidade?\n");
    printf("1. Baralho sujo\n");
    printf("2. Baralho limpo\n");
    printf("3. Baralho limpo sem o 4\n");
    printf("Escolha: ");
    scanf("%d", &modalidade);
    
    if (modalidade == 1) tamanho = 40;
    if (modalidade == 2) tamanho = 28;
    if (modalidade == 3) tamanho = 24;
    
    baralho = (int *)malloc(tamanho * sizeof(int));
    maos = (int *)malloc(3 * modo * sizeof(int));
    
    while (nos != 12 && eles != 12) {
        maior = 0;
        embaralhar(baralho, tamanho, maos, modo);
        for (int i = 0;i < modo; i++) {
            printf("Jogador %d: ", i + 1);
            scanf("%d", &atual);
            if (atual > maior) {
                maior = atual;
                quemFez = i + 1;
            }
        }
        
    free(baralho);
    free(maos);
    return 0;
}