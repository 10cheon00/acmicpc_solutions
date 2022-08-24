/*
 * 1106 호텔
 * 골드V
 */
#include <iostream>
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))

int main() {
  int A, N, cost[21], acc[21], dp[1101]{0}, accMax = 0;
  scanf("%d %d", &A, &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &cost[i], &acc[i]);
    if (accMax < acc[i]) {
      accMax = acc[i];
    }
  }
  for (int i = 1; i <= A + accMax; i++) {
    dp[i] = 987654321;
  }
  int min = 987654321;
  for (int i = 1; i <= N; i++) {
    for (int j = acc[i]; j <= A + accMax; j++) {
      dp[j] = MIN(dp[j], dp[j - acc[i]] + cost[i]);
      if (j >= A && dp[j] < min) {
        min = dp[j];
      }
    }
  }
  printf("%d", min);
}