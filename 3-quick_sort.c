#include "sort.h"

void swap(int* a, int* b, int *array, size_t size) 
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
    print_array((const int*)array, size);
}

int partition (int arr[], int low, int high, int *array, size_t size) {
    int pivot = arr[high];  
    int i = (low - 1), j;  

    for (j = low; j <= high- 1; j++) {
        if (arr[j] < pivot) {
            i++;  
            swap(&arr[i], &arr[j], array, size);
        }
    }
    swap(&arr[i + 1], &arr[high], array, size);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *array, size_t size) {
    if (low < high) {
        int pi;
        
        pi = partition(arr, low, high, array, size);
        quickSort(arr, low, pi - 1, array, size);
        quickSort(arr, pi + 1, high, array, size);
    }
}

void quick_sort(int *array, size_t size) 
{
    quickSort(array, 0, size-1, array, size);
}
