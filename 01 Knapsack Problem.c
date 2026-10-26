#include <stdio.h>

int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}

int main(){
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], profit[n + 1];

    printf("Enter weights of items:\n");
    for (int i = 1; i <= n; i++){
        scanf("%d", &weight[i]);
    }

    printf("Enter profits of items:\n");
    for (int i = 1; i <= n; i++){
        scanf("%d", &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int V[n + 1][W + 1];

    for (int w = 0; w <= W; w++){
        V[0][w] = 0;
    }

    for (int i = 1; i <= n; i++){
        V[i][0] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int w = 0; w <= W; w++){
            if (weight[i] <= w){
                V[i][w] = max(profit[i] + V[i - 1][w - weight[i]], V[i - 1][w]);
            }
            else{
                V[i][w] = V[i - 1][w];
            }
        }
    }

    printf("\nMaximum Profit = %d\n", V[n][W]);

    return 0;
}
