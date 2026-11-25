#include "registro.h"


void gerar_vetor(Registro arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        arr[i].valor = rand();
    }
}


void copiar_vetor(Registro original[], Registro copia[], int n) {
    for (int i = 0; i < n; i++) {
        copia[i] = original[i];
    }
}


void imprimir_vetor(Registro arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Valor: %d\n",
               arr[i].id, arr[i].valor);
    }
}


void mostrar_tempo(const char *nome, clock_t inicio, clock_t fim) {
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
        printf("Erro ao alocar memoria.\n");
        free(original);
        free(copia);
        return 1;
    }

    gerar_vetor(original, n);

    clock_t inicio, fim;

    printf("Quantidade de registros: %d\n\n", n);

    if (n == 10) {
        printf("Vetor original:\n");
        imprimir_vetor(original, n);
        printf("\n");
    }

   
    copiar_vetor(original, copia, n);

    inicio = clock();
    bubble_sort(copia, n);
    fim = clock();

    mostrar_tempo("Bubble Sort", inicio, fim);

   
    copiar_vetor(original, copia, n);

    inicio = clock();
    selection_sort(copia, n);
    fim = clock();

    mostrar_tempo("Selection Sort", inicio, fim);

  
    copiar_vetor(original, copia, n);

    inicio = clock();
    insertion_sort(copia, n);
    fim = clock();

    mostrar_tempo("Insertion Sort", inicio, fim);

    
    copiar_vetor(original, copia, n);

    inicio = clock();
    merge_sort(copia, n);
    fim = clock();

    mostrar_tempo("Merge Sort", inicio, fim);

    
    copiar_vetor(original, copia, n);

    inicio = clock();
    quick_sort(copia, 0, n - 1);
    fim = clock();

    mostrar_tempo("Quick Sort", inicio, fim);

    if (n == 10) {
        printf("\nVetor ordenado:\n");
        imprimir_vetor(copia, n);
    }

    free(original);
    free(copia);

    return 0;
}
