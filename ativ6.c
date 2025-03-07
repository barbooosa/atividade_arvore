#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE_1 100
#define MAX_SIZE_2 1000
#define MAX_SIZE_3 5000
#define MAX_SIZE_4 10000

void bubbleSort(int arr[], int size, long *comparisons, long *movements);
void selectionSort(int arr[], int size, long *comparisons, long *movements);
void fillArray(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    int arr1[MAX_SIZE_1], arr2[MAX_SIZE_2], arr3[MAX_SIZE_3], arr4[MAX_SIZE_4];
    clock_t start, end;
    long comparisons, movements;

    fillArray(arr1, MAX_SIZE_1);
    comparisons = movements = 0;
    start = clock();
    bubbleSort(arr1, MAX_SIZE_1, &comparisons, &movements);
    end = clock();
    printf("\nBubble Sort - 100 elementos:\n");
    printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);

    fillArray(arr1, MAX_SIZE_1);
    comparisons = movements = 0;
    start = clock();
    selectionSort(arr1, MAX_SIZE_1, &comparisons, &movements);
    end = clock();
    printf("\nSelection Sort - 100 elementos:\n");
    printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);
    
    fillArray(arr2, MAX_SIZE_2);
    comparisons = movements = 0;
    start = clock();
    bubbleSort(arr2, MAX_SIZE_2, &comparisons, &movements);
    end = clock();
    printf("\nBubble Sort - 1000 elementos:\n");
    printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);

    fillArray(arr2, MAX_SIZE_2);
    comparisons = movements = 0;
    start = clock();
    selectionSort(arr2, MAX_SIZE_2, &comparisons, &movements);
    end = clock();
    printf("\nSelection Sort - 1000 elementos:\n");
     printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);

    fillArray(arr3, MAX_SIZE_3);
    comparisons = movements = 0;
    start = clock();
    bubbleSort(arr3, MAX_SIZE_3, &comparisons, &movements);
    end = clock();
    printf("\nBubble Sort - 10000 elementos:\n");
   printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);

    fillArray(arr3, MAX_SIZE_3);
    comparisons = movements = 0;
    start = clock();
    selectionSort(arr3, MAX_SIZE_3, &comparisons, &movements);
    end = clock();
    printf("\nSelection Sort - 10000 elementos:\n");
    printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);

    fillArray(arr4, MAX_SIZE_4);
    comparisons = movements = 0;
    start = clock();
    selectionSort(arr4, MAX_SIZE_4, &comparisons, &movements);
    end = clock();
    printf("\nSelection Sort - 10000 elementos:\n");
    printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);

    fillArray(arr4, MAX_SIZE_4);
    comparisons = movements = 0;
    start = clock();
    bubbleSort(arr4, MAX_SIZE_4, &comparisons, &movements);
    end = clock();
    printf("\nBubble Sort - 10000 elementos:\n");
   printf("Tempo de execução: %ld ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Comparações: %ld\n", comparisons);
    printf("Movimentações: %ld\n", movements);
    return 0;
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size, long *comparisons, long *movements) {
    int aux;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                (*movements) += 3;
            }
        }
    }
}

void selectionSort(int arr[], int size, long *comparisons, long *movements) {
    int minIndex, aux;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            (*comparisons)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            aux = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = aux;
            (*movements) += 3;
        }
    }
}

