/*
 * 2293 µ¿Àü1
 * °ñµåV
 */
#include <iostream>
int main() {
    int dp[10001]{ 1 }, arr[101], N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = arr[i]; j <= K; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }
    printf("%d", dp[K]);
}