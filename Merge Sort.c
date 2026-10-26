#include <stdio.h>

// Merge two sorted parts
void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy elements into temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // Compare and merge elements in sorted order
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements from left array
    while (i < n1)
        arr[k++] = L[i++];

    // Copy remaining elements from right array
    while (j < n2)
        arr[k++] = R[j++];
}

// Divide the array and sort each part
void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);       // Sort left half
        mergeSort(arr, mid + 1, right);  // Sort right half

        merge(arr, left, mid, right);   // Merge both halves
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
