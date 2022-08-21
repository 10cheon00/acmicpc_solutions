/*
 * 1535 ¾È³ç
 * ½Ç¹öII
 */
#include <iostream>
#define MAX(X, Y) (((X)>(Y))?(X):(Y))
int N, hp[21]{ 0 }, joy[21]{ 0 }, dp[21][101]{ 0 };
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &hp[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &joy[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < 101; j++) {
            if (j > hp[i]) {
                dp[i][j] = MAX(dp[i - 1][j - hp[i]] + joy[i], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d", dp[N][100]);
}