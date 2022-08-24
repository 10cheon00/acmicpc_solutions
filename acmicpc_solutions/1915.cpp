/*
 * 1915 가장 큰 정사각형
 * 골드IV
 */

// 소요시간이 572ms여서 조금 아쉽다.
// 대신 메모리는 3000kb로 다른 사람보다 훨씬 적게 썼다.
#include <iostream>
char dp[1001][1001]{0};
int main() {
  int N, M, max = 0, len = 2;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf(" %c", &dp[i][j]);
      dp[i][j] = dp[i][j] == '1' ? 1 : 0;
      if (dp[i][j]) {
        max = 1;
      }
    }
  }
  while (N && M) {
    for (int i = 0; i < N - 1; i++) {
      for (int j = 0; j < M - 1; j++) {
        dp[i][j] = dp[i][j] == dp[i][j + 1] && dp[i][j + 1] == dp[i + 1][j] &&
                   dp[i + 1][j] == dp[i + 1][j + 1] && dp[i][j] == 1;
        if (max < dp[i][j] * len * len) {
          max = dp[i][j] * len * len;
        }
      }
    }
    N--;
    M--;
    len++;
  }
  printf("%d", max);
}