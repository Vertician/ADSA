#include <stdio.h>
#include <string.h>

int main(){
    char X[50], Y[50], lcs[50];
    int m, n, i, j, k;
    int c[50][50];

    printf("Enter first string: ");
    scanf("%49s", X);

    printf("Enter second string: ");
    scanf("%49s", Y);

    m = strlen(X);
    n = strlen(Y);

    for(i = 0; i <= m; i++)
        c[i][0] = 0;

    for(j = 0; j <= n; j++)
        c[0][j] = 0;

    // Fill the LCS matrix
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(X[i-1] == Y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else if(c[i-1][j] > c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    }

    // Print the matrix
    printf("\nLCS Matrix:\n");

    for(i = 0; i <= m; i++){
        for(j = 0; j <= n; j++)
            printf("%d\t", c[i][j]);

        printf("\n");
    }

    // Find the LCS
    i = m;
    j = n;
    k = 0;

    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
            lcs[k++] = X[i-1];
            i--;
            j--;
        }
        else if(c[i-1][j] > c[i][j-1])
            i--;
        else
            j--;
    }

    lcs[k] = '\0';

    // Reverse the LCS
    for(i = 0, j = k-1; i < j; i++, j--){
        char temp = lcs[i];
        lcs[i] = lcs[j];
        lcs[j] = temp;
    }

    printf("\nLength of LCS = %d", c[m][n]);
    printf("\nLCS = %s\n", lcs);

    return 0;
}
