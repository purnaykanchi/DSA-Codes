#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    
    for(j = low; j <= high - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int array[size];
    printf("Enter array elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    quicksort(array, 0, size - 1);
    
    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}