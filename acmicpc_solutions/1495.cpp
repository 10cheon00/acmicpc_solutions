/*
 * 1495 기타리스트
 * 실버I
 */
#include<iostream>
int main() {
    scanf("%d %d %d", &N, &S, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    dp[0][S] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i - 1][j] && j + arr[i] <= M) {
                dp[i][j + arr[i]] = 1;
            }
            if (dp[i - 1][j] && 0 <= j - arr[i]) {
                dp[i][j - arr[i]] = 1;
            }
        }
    }
    int max = -1;
    for (int i = 0; i <= M; i++) {
        if (dp[N][i]) {
            max = i;
        }
    }
    printf("%d", max);
}