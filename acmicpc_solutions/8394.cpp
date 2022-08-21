#include <iostream>
#pragma warning(disable:4996)

int main() {
    int N;
    int* dp = new int[10000001]{ 1,1 };
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
    }
    printf("%d", dp[N]);
    delete dp;
}