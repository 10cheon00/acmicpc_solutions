/*
 * 1577 도로의 개수
 * 골드V
 */
#include<iostream>
#pragma warning(disable:4996)
#define ABS(X) ((X)>0)?(X):(-X)
int impossible[50][3], N, M, K, c=0;
long long dp[101][101];
int main() {
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    int x, y, xx, yy;
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d %d", &x, &y, &xx, &yy);
        impossible[i][0] = x > xx ? x : xx;
        impossible[i][1] = y > yy ? y : yy;
        impossible[i][2] = ABS((x - xx) + 2 * (y - yy));
    }
    dp[0][0] = 1;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            long long l, t;
            if (i == 0) {
                l = dp[i][j - 1];
                t = 0;
            }
            else if (j == 0) {
                l = 0;
                t = dp[i - 1][j];
            }
            else {
                l = dp[i][j - 1];
                t = dp[i - 1][j];
            }

            int k;
            for (k = 0; k < K; k++) {
                if (j == impossible[k][0] && i == impossible[k][1]) {
                    if (impossible[k][2] == 1) {
                        l = 0;
                    }
                    else {
                        t = 0;
                    }
                }
            }
            dp[i][j] = l + t;
        }
    }
    printf("%lld", dp[M][N]);
}