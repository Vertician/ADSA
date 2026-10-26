#include <stdio.h>
#include <time.h>

int i, j, n, m;
int arr[100];

void binary_search(int m) {
    int low = 1;
    int high = n;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == m) {
            printf("Element found %d\n", m);
            return;
        }
        if (arr[mid] < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("No element found %d\n", m);
}

int main() {
    printf("Enter the size: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    for (j = 1; j <= n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    printf("Enter the number you want to search: ");
    scanf("%d", &m);

    clock_t start = clock();
    binary_search(m);
    clock_t end = clock();

    double run_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Searching run time: %f seconds\n", run_time);

    return 0;
}
