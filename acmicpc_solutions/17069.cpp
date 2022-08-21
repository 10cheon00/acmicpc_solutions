#include <iostream>
struct Node {
    long long left, top, topleft;
};
int N, arr[33][33]{ 0 };
Node dp[33][33]{ 0 };
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    dp[1][2].left = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            if(!arr[i][j+1]) 
                dp[i][j + 1].left += dp[i][j].left + dp[i][j].topleft;
            if (!(arr[i+1][j + 1] + arr[i][j+1] + arr[i+1][j])) 
                dp[i + 1][j + 1].topleft += dp[i][j].left + dp[i][j].topleft + dp[i][j].top;
            if (!arr[i+1][j]) 
                dp[i + 1][j].top += dp[i][j].topleft + dp[i][j].top;
        }
    }

    printf("%lld", dp[N][N].left + dp[N][N].top + dp[N][N].topleft);
}   
