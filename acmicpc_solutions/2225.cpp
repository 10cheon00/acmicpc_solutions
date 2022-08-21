/*
 * 2225 «’∫–«ÿ
 * ∞ÒµÂV
 */
#include <iostream>
int dp[201][201]{ 0 };
int S(int n, int k) {
    if (k == 1) {
        return 1;
    }
    if (dp[n][k]) {
        return dp[n][k];
    }
    for (int i = n; i >= 0; i--) {
        dp[n][k] = (dp[n][k] + S(i, k-1)) % 1000000000;
    }
    return dp[n][k];
}
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%d", S(N, K));
}