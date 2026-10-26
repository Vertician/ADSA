#include <stdio.h>
#include <stdlib.h>

int isSafe(int row, int col, int board[], int N) {
    for (int i = 0; i < row; i++) {

        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

int solveNQueens(int row, int board[], int N) {
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return 1;
    }

    int foundsolution = 0;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, board, N)) {
            board[row] = col;
            foundsolution += solveNQueens(row + 1, board, N);
        }
    }
    return foundsolution;
}

int main() {
    int N;
    printf("Enter the value of N for the N-Queens Problem: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Please enter a valid positive integer for N.\n");
        return 1;
    }

    int board[N];

    printf("\nSolutions to %d-Queens Problem:\n\n", N);
    int totalSolutions = solveNQueens(0, board, N);
    printf("Total Solutions: %d\n", totalSolutions);

    return 0;
}
