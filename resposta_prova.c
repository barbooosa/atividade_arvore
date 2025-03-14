#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define tam 15
// definindo uma estrutura para armazenamento do nome e pre�o
typedef struct {
    char nome[50];
    float preco;
} Produto;

// Fun��o Bubble Sort
// Passando a estrutura produtos comoparametros
void bubbleSort(Produto produtos[], int n) {
    int i, j;
    Produto temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (produtos[j].preco > produtos[j + 1].preco) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

// Fun��o Selection Sort
// Passando a estrutura produtos comoparametros
void selectionSort(Produto produtos[], int n) {
    int i, j, min_idx;
    Produto temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (produtos[j].preco < produtos[min_idx].preco) {
                min_idx = j;
            }
        }
        temp = produtos[min_idx];
        produtos[min_idx] = produtos[i];
        produtos[i] = temp;
    }
}

// Fun��o para imprimir os produtos ordenados
void printProdutos(Produto produtos[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s - R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    
	printf("\n");
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    
	Produto produtos[tam] = {
        {"Teclado", 120.50}, {"Mouse", 80.00}, {"Monitor", 550.00}, {"Fone", 200.00}, 
        {"Notebook", 3500.00}, {"Cadeira Gamer", 1200.00}, {"Impressora", 650.00}, {"Pendrive", 50.00}, 
        {"SSD 1TB", 420.00}, {"HD 2TB", 350.00}, {"Processador", 1500.00}, {"Placa de V�deo", 2500.00}, 
        {"Gabinete", 400.00}, {"Mem�ria RAM", 300.00}, {"Fonte 750W", 600.00}
    };
    int n = 15;

    // Selection Sort
    Produto prodSelec[tam];
    for (int i = 0; i < n; i++) 
		prodSelec[i] = produtos[i];

    clock_t start = clock();
    selectionSort(prodSelec, n);
    clock_t end = clock();
    printf("Produtos ordenados (Selection Sort):\n");
    printProdutos(prodSelec, n);
    printf("Tempo de execu��o (Selection Sort): %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // Bubble Sort
    Produto prodBubble[tam];
    for (int i = 0; i < n; i++) prodBubble[i] = produtos[i];

    start = clock();
    bubbleSort(prodBubble, n);
    end = clock();
    printf("Produtos ordenados (Bubble Sort):\n");
    printProdutos(prodBubble, n);
    printf("Tempo de execu��o (Bubble Sort): %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    return 0;
}


