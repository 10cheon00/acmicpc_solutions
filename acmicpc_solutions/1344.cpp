/*
 * 1344 축구
 * 골드IV
 */
#include <iostream>
#include <cmath>
#define LEN 19
int dp[LEN][LEN]{ 0 };
int f(int n, int k) {
    if (k == n || k == 0) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    if (!dp[n][k]) {
        dp[n][k] = f(n - 1, k - 1) + f(n - 1, k);
    }
    return dp[n][k];
}
int main() {
    int A, B, nonePrimes[LEN] = { 1,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1 };
    scanf("%d %d", &A, &B);
    double res = 0.0f;
    // 어떤 팀도 소수로 득점하지 않을 확률.
    // 18C0 18C1 18C4 ... 18C18
    for (int i = 0; i < LEN; i++) {
        if (nonePrimes[i]) {
            double p = std::pow((double)A / 100, i) * std::pow(1.0f - (double)A / 100, LEN - i - 1) * f(LEN - 1, i);
            for (int j = 0; j < LEN; j++) {
                if (nonePrimes[j]) {
                    res += p * std::pow((double)B / 100, j) * std::pow(1.0f - (double)B / 100, LEN - j - 1) * f(LEN - 1, j);
                }
            }
        }
    }
    printf("%.15f", 1.0f - res);
}