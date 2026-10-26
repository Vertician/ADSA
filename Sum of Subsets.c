
#include <stdio.h>

int w[20], x[20], N, M, totalSolutions = 0;

void sumOfSubsets(int index, int sum)
{
    int i;

    if (sum == M)
    {
        totalSolutions++;

        printf("Solution %d: { ", totalSolutions);

        for (i = 0; i < N; i++){
            if (x[i] == 1)
                printf("%d ", w[i]);
        }

        printf("}\n");
        return;
    }

    if (index == N || sum > M)
        return;

    /* Include the current element */
    x[index] = 1;
    sumOfSubsets(index + 1, sum + w[index]);

    /* Exclude the current element */
    x[index] = 0;
    sumOfSubsets(index + 1, sum);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    if (N <= 0 || N > 20)
    {
        printf("Enter N between 1 and 20.\n");
        return 1;
    }

    printf("Enter positive elements in increasing order:\n");

    for (i = 0; i < N; i++)
    {
        scanf("%d", &w[i]);

        if (w[i] <= 0 || (i > 0 && w[i] < w[i - 1]))
        {
            printf("Elements must be positive and sorted.\n");
            return 1;
        }
    }

    printf("Enter target sum: ");
    scanf("%d", &M);

    printf("\nSubsets with sum %d:\n", M);

    sumOfSubsets(0, 0);

    if (totalSolutions == 0)
        printf("No subset found.\n");

    printf("Total Solutions: %d\n", totalSolutions);

    return 0;
}
