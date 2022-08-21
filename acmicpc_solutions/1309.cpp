/*
 * 1309 동물원
 * 실버I
 */
#include<iostream>
#pragma warning(disable:4996)
int main() {
    int N;
    scanf("%d", &N);
    int** dp = new int* [N];
    for (int i = 0; i < N; i++) {
        dp[i] = new int[3];
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
    }
    printf("%d", (dp[N-1][0] + dp[N-1][1] + dp[N-1][2]) % 9901);
    for (int i = 0; i < N; i++) {
        delete[]dp[i];
    }
    delete[]dp;
}
