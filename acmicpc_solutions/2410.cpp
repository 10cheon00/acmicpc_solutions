#include <iostream>
int main() {
    int N, K=0, arr[21], *dp;
    scanf("%d", &N);
    int j=1;
    for (int i = 1; N >= j; i++) {
        arr[i] = j;
        j *= 2;
        K++;
    }
    dp = new int[1000001]{ 1 };

    for (int i = 1; i <= K; i++) {
        for (int j = arr[i]; j <= N; j++) {
            dp[j] = (dp[j] + dp[j - arr[i]]) % 1000000000;
        }
    }

    printf("%d", dp[N]);
    delete[] dp;
}