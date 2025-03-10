#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para comparar duas strings
int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void quicksort(char *arr[], int low, int high) {
    if (low < high) {
        int pivot = low + (high - low) / 2;
        int left = low;
        int right = high;
        
        while (left <= right) {
            while (strcmp(arr[left], arr[pivot]) < 0) left++;
            while (strcmp(arr[right], arr[pivot]) > 0) right--;
            
            if (left <= right) {
                // Troca as palavras
                char *temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }

        // Recursão para as duas metades
        quicksort(arr, low, right);
        quicksort(arr, left, high);
    }
}

void testar_desempenho(char *dicionario[], int n) {
    clock_t inicio = clock();

    quicksort(dicionario, 0, n - 1);

    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %.4f segundos\n", tempo_execucao);
}

int main() {
    int n = 10000;
    char *dicionario[n];
    
    for (int i = 0; i < n; i++) {
        dicionario[i] = (char *)malloc(10 * sizeof(char));  
        snprintf(dicionario[i], 10, "palavra%d", i);
    }

    // Embaralha as palavras para simular uma lista desordenada
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        char *temp = dicionario[i];
        dicionario[i] = dicionario[j];
        dicionario[j] = temp;
    }

    testar_desempenho(dicionario, n);

    for (int i = 0; i < n; i++) {
        free(dicionario[i]);
    }

    return 0;
}
