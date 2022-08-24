/*
 * 1229 육각수
 * 골드IV
 */
#include <iostream>
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))
int main() {
  int N, hex, i = 1, dp[1000001]{0};
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    dp[i] = 987654321;
  }
  while (hex <= N) {
    hex += 4 * i++ - 3;
    for (int j = hex; j <= N; j++) {
      dp[j] = MIN(dp[j], dp[j - hex] + 1);
    }
  }
  printf("%d", dp[N]);
}