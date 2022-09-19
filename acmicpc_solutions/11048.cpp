/*
 * 11048 이동하기
 * 실버I
 */
#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int dp[1001][1001]{0}, arr[1001][1001]{0};
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      dp[i][j] =
          MAX(dp[i - 1][j], MAX(dp[i - 1][j - 1], dp[i][j - 1])) + arr[i][j];
    }
  }
  printf("%d", dp[N][M]);
}