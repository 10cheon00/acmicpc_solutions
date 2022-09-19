/*
 * 4883 삼각그래프
 * 실버I
 */
#include <iostream>
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))
int main() {
  for (int cases = 1;; cases++) {
    int arr[100001][3]{0}, dp[100001][3]{0};
    int N;
    scanf("%d", &N);
    if (!N) {
      return 0;
    }
    for (int i = 1; i <= N; i++) {
      scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    dp[1][0] = 987654321;
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][1] + arr[1][2];
    for (int i = 2; i <= N; i++) {
      dp[i][0] = arr[i][0] + MIN(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] =
          arr[i][1] +
          MIN(dp[i - 1][0], MIN(dp[i - 1][1], MIN(dp[i - 1][2], dp[i][0])));
      dp[i][2] = arr[i][2] + MIN(dp[i - 1][1], MIN(dp[i - 1][2], dp[i][1]));
    }
    printf("%d. %d\n", cases, dp[N][1]);
  }
}