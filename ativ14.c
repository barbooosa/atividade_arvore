#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low + 1;  
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    // Coloca o pivô no lugar certo
    swap(arr, low, i - 1);
    return i - 1;
}

// Função do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  
    int n = sizeof(arr) / sizeof(arr[0]);  

    printf("Array original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);  

    printf("Array ordenado:\n");
    printArray(arr, n);  

    return 0;
}
