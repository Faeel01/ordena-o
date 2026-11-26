#include "registro.h"


void gerarVetor(Registro arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        arr[i].valor = rand();
    }
}


void copiarVetor(Registro original[], Registro copia[], int n) {
    for (int i = 0; i < n; i++) {
        copia[i] = original[i];
    }
}


void imprimirVetor(Registro arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Valor: %d\n",
               arr[i].id, arr[i].valor);
    }
}


void mostrarTempo(const char *nome, clock_t inicio, clock_t fim) {
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("%s: %.6f segundos\n", nome, tempo);
    fflush(stdout);
}

int main(void) {
    int n = 10;

    srand(time(NULL));

    Registro *original = malloc(n * sizeof(Registro));
    Registro *copia = malloc(n * sizeof(Registro));

    if (original == NULL || copia == NULL) {
        printf("Erro ao alocar memoria\n");
        free(original);
        free(copia);
        return 1;
    }

    gerarVetor(original, n);

    clock_t inicio, fim;

    printf("Quantidade de registros: %d\n\n", n);

    if (n == 10) {
        printf("Vetor original:\n");
        imprimirVetor(original, n);
        printf("\n");
    }

   
    copiarVetor(original, copia, n);

    inicio = clock();
    bubble_sort(copia, n);
    fim = clock();

    mostrarTempo("Bubble Sort", inicio, fim);

   
    copiarVetor(original, copia, n);

    inicio = clock();
    selection_sort(copia, n);
    fim = clock();

    mostrarTempo("Selection Sort", inicio, fim);

  
    copiarVetor(original, copia, n);

    inicio = clock();
    insertion_sort(copia, n);
    fim = clock();

    mostrarTempo("Insertion Sort", inicio, fim);

    
    copiarVetor(original, copia, n);

    inicio = clock();
    merge_sort(copia, 0, n - 1);
    fim = clock();

    mostrarTempo("Merge Sort", inicio, fim);

    
    copiarVetor(original, copia, n);

    inicio = clock();
    quick_sort(copia, 0, n - 1);
    fim = clock();

    mostrarTempo("Quick Sort", inicio, fim);

    if (n == 10) {
        printf("\nVetor ordenado:\n");
        imprimirVetor(copia, n);
    }

    free(original);
    free(copia);

    return 0;
}
