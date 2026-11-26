#include "registro.h"


void bubble_sort(Registro arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].valor > arr[j + 1].valor) {
                Registro temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}


void selection_sort(Registro arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (arr[j].valor < arr[min].valor)
                min = j;

        Registro temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


void insertion_sort(Registro arr[], int n) {
    for (int i = 1; i < n; i++) {
        Registro key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].valor > key.valor) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void merge(Registro arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Registro L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        arr[k++] = (L[i].valor <= R[j].valor)
                    ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void merge_sort(Registro arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int partition(Registro arr[], int low, int high) {
    Registro pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].valor < pivot.valor) {
            Registro temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Registro temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(Registro arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
