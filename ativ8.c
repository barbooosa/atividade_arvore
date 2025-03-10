#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size) {
    int aux;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

// Implementação correta da função printArray
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 2, 3, 3, 4, 12, 567, 3, 5, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
