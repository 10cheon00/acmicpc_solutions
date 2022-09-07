/*
 * 9084 동전
 * 골드V
 */
#include <iostream>
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))
int main() {
  int T;
  scanf("%d", &T);
  for (int cases = 0; cases < T; cases++) {
    int N, M, arr[21]{0}, dp[10001]{0};
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
      scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
      for (int j = arr[i]; j <= M; j++) {
        dp[j] = dp[j] + dp[j - arr[i]];
      }
    }
    printf("%d\n", dp[M]);
  }
}