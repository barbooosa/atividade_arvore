#include <stdio.h>
#include <time.h>
#include <locale.h>

// Fun��o Bubble Sort
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fun��o Insertion Sort
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fun��o para imprimir o array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	
    float notas[] = {7.5, 9.2, 6.8, 8.0, 7.1};
    int n = sizeof(notas) / sizeof(notas[0]);

    // Bubble Sort
    float notasBubble[n];
    for (int i = 0; i < n; i++) notasBubble[i] = notas[i];

    clock_t start = clock();
    bubbleSort(notasBubble, n);
    clock_t end = clock();
    printf("Notas ordenadas (Bubble Sort): ");
    printArray(notasBubble, n);
    printf("Tempo de execu��o (Bubble Sort): %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // Insertion Sort
    float notasInsert[n];
    for (int i = 0; i < n; i++) notasInsert[i] = notas[i];

    start = clock();
    insertionSort(notasInsert, n);
    end = clock();
    printf("Notas ordenadas (Insertion Sort): ");
    printArray(notasInsert, n);
    printf("Tempo de execu��o (Insertion Sort): %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    return 0;
}

