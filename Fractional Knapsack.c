
#include <stdio.h>

int main(){
    int n, W, i, j, temp;
    int weight[50], profit[50];
    float ratio[50], totalProfit = 0, fraction, tempR;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }

    printf("Enter profits of items:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    // Calculate profit/weight ratio
    for (i = 0; i < n; i++){
        ratio[i] = (float)profit[i] / weight[i];
    }

    // Sort items in descending order of ratio
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (ratio[i] < ratio[j]){
                tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // Select items
    for (i = 0; i < n; i++){
        if (weight[i] <= W){
            totalProfit = totalProfit + profit[i];
            W = W - weight[i];
        }
        else{
            fraction = (float)W / weight[i];
            totalProfit = totalProfit + profit[i] * fraction;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
