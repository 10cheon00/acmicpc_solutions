#include <iostream>
int main() {
  int dp[16][16]{0};
  int K, N, M, nn, mm;
  scanf("%d %d %d", &N, &M, &K);
  if (!K) {
    K = N * M;
  }
  nn = (K + M - 1) / M;
  mm = K % M ? K % M : M;
  dp[0][1] = 1;
  for (int i = 1; i <= nn; i++) {
    for (int j = 1; j <= mm; j++) {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
  }
  if (K != N * M) {
    for (int i = nn; i <= N; i++) {
      for (int j = mm; j <= M; j++) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }
  }
  printf("%d", dp[N][M]);
}