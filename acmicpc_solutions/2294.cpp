/*
 * 2294 µ¿Àü 2
 * °ñµåV
 */
#include <iostream>
#pragma warning(disable:4996)
#define MIN(X, Y) ((X)>(Y)?(Y):(X))
int main() {
    int dp[10001]{ 0 }, arr[101], N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= K; i++) {
        dp[i] = 987654321;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = arr[i]; j <= K; j++) {
            dp[j] = MIN(dp[j], dp[j - arr[i]] + 1);
        }
    }
    printf("%d", 987654321==dp[K]?-1:dp[K]);
}