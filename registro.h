#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int valor;
} Registro;

void bubble_sort(Registro arr[], int n);
void selection_sort(Registro arr[], int n);
void insertion_sort(Registro arr[], int n);
void merge_sort(Registro arr[], int l, int r);
void quick_sort(Registro arr[], int low, int high);

