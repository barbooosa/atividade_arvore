#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    
    if (arr[low] > arr[mid]) swap(arr, low, mid);
    if (arr[low] > arr[high]) swap(arr, low, high);
    if (arr[mid] > arr[high]) swap(arr, mid, high);
    
    return mid;
}

int partition(int arr[], int low, int high) {
    int pivotIndex = medianOfThree(arr, low, high);
    int pivot = arr[pivotIndex];
    
    swap(arr, pivotIndex, high);
    
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high); 
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Array original (QuickSort com mediana de 3 elementos):\n");
    printArray(arr1, n);
    
    quickSort(arr1, 0, n - 1); 
    printf("Array ordenado (QuickSort com mediana de 3 elementos):\n");
    printArray(arr1, n);  
    printf("\nArray original (QuickSort tradicional):\n");
    printArray(arr2, n);

    quickSort(arr2, 0, n - 1);  
    printf("Array ordenado (QuickSort tradicional):\n");
    printArray(arr2, n);  
    
    return 0;
}
