#include <stdio.h>

// Partition the array using the first element as pivot
int part(int arr[], int low, int high, int n){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j){
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    // Print the array after partitioning
    printf("After pivot %d: ", pivot);

    for (int k = 0; k < n; k++)
        printf("%d ", arr[k]);

    printf("\n");

    return j;
}

// Recursively sort the array
void quickSort(int arr[], int low, int high, int n){
    if (low < high){
        int pi = part(arr, low, high, n);

        // Sort elements before the pivot
        quickSort(arr, low, pi - 1, n);

        // Sort elements after the pivot
        quickSort(arr, pi + 1, high, n);
    }
}

int main(){
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Input array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nIterations:\n");

    // Sort the complete array
    quickSort(arr, 0, n - 1, n);

    printf("Final array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
