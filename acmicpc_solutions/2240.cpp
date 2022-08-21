/*
 * 2240 자두나무
 * 골드V
 */
#include <iostream>
#define MAX(X, Y) ((X)>(Y)?(X):(Y))
int main() {
    int N, W, arr[1001], dp[31][1001]{ 0 };
    scanf("%d %d", &N, &W);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        dp[0][i] = (arr[i] == 1) + dp[0][i-1];
    }

    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1] + (arr[j]-1 == i%2));
        }
    }
    printf("%d", dp[W][N]);
}