#include <stdio.h>
#include <stdlib.h>

int board[20];
int n, count = 0;

int isSafe(int row, int col) {
    for(int i = 1; i < row; i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int row) {
    for(int col = 1; col <= n; col++) {
        if(isSafe(row, col)) {
            board[row] = col;

            if(row == n) {
                count++;
                printf("\nSolution %d:\n", count);
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++) {
                        if(board[i] == j)
                            printf("Q ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
            } else {
                solve(row + 1);
            }
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if(n <= 0 || n > 20) {
        printf("Invalid input\n");
        return 0;
    }

    solve(1);

    if(count == 0)
        printf("No solutions found\n");

    return 0;
}
