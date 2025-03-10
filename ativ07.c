#include <stdio.h>

void selectionSortDesc(int arr[], int n) {
    int i, j, maxIdx, temp;
    for (i = 0; i < n - 1; i++) {
        maxIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        //troca de elementos
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {790, 32131, 4124, 64643, 10, 1240, 145};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    printArray(arr, n);
    
    selectionSortDesc(arr, n);
    
    printf("Array ordenado em ordem decrescente: \n");
    printArray(arr, n);
    
    return 0;
}
