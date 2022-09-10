/*
 * 3067 coins
 * 골드V
 */
#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int main() {
  int T, N, M, coins[21];

  scanf("%d", &T);
  for (int k = 0; k < T; k++) {
    int dp[10001]{1};
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
      scanf("%d", &coins[i]);
    }
    scanf("%d", &M);
    for (int i = 1; i <= N; i++) {
      for (int j = coins[i]; j <= M; j++) {
        dp[j] += dp[j - coins[i]];
      }
    }
    printf("%d\n", dp[M]);
  }
}