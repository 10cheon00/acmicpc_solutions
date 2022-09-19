/*
 * 다이나믹이 뭐에요?
 * 실버III
 */
#include <iostream>
#define D 1000000007
int main() {
  int N, M;
  long long dp[1001][1001]{0};
  scanf("%d %d", &N, &M);
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      dp[i][j] =
          (dp[i - 1][j - 1] % D + dp[i - 1][j] % D + dp[i][j - 1] % D) % D;
    }
  }
  printf("%lld", dp[N][M]);
}