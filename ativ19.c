#include <stdio.h>
#include <string.h>

#define MAX_JOGADORES 100

typedef struct {
    char nome[50];
    int pontos;
} Jogador;

void insertionSort(Jogador ranking[], int n) {
    for (int i = 1; i < n; i++) {
        Jogador chave = ranking[i];
        int j = i - 1;
        while (j >= 0 && ranking[j].pontos < chave.pontos) { //ordem crescente
            ranking[j + 1] = ranking[j];
            j--;
        }
        ranking[j + 1] = chave;
    }
}

void adicionarJogador(Jogador ranking[], int *n, Jogador novo) {
    if (*n >= MAX_JOGADORES) {
        printf("Ranking cheio!\n");
        return;
    }
    ranking[*n] = novo; // adiciona o novo jogador no final
    (*n)++;
    insertionSort(ranking, *n); // reordena o ranking
}

void imprimirRanking(Jogador ranking[], int n) {
    printf("Ranking de Jogadores:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %d pontos\n", i + 1, ranking[i].nome, ranking[i].pontos);
    }
}

int main() {
    Jogador ranking[MAX_JOGADORES];
    int n = 0;

    Jogador j1 = {"Alice", 150};
    Jogador j2 = {"Bob", 200};
    Jogador j3 = {"Charlie", 180};

    adicionarJogador(ranking, &n, j1);
    adicionarJogador(ranking, &n, j2);
    adicionarJogador(ranking, &n, j3);

    Jogador novoJogador = {"David", 170};
    adicionarJogador(ranking, &n, novoJogador);

    imprimirRanking(ranking, n);
    
    return 0;
}
