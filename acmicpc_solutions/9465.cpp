/*
 * 9465 스티커
 * 실버I
왼쪽 고르기 or 오른쪽 고르기 or 안고르기
직전에 왼쪽 골랐다면 이번엔 오른쪽 고르기 or 안고르기
직전에 오른쪽 골랐다면 이번엔 왼쪽 고르기 or 안고르기
*/
#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int main() {
  int T;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; cases++) {
    int N, dp[3][100001]{0}, arr[2][100001]{0};
    scanf("%d", &N);

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= N; j++) {
        scanf("%d", &arr[i][j]);
      }
    }

    for (int i = 1; i <= N; i++) {
      dp[0][i] = MAX(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];
      dp[1][i] = MAX(dp[0][i - 1], dp[2][i - 1]) + +arr[1][i];
      dp[2][i] = MAX(dp[0][i - 1], MAX(dp[1][i - 1], dp[2][i - 1]));
    }
    printf("%d\n", MAX(dp[0][N], MAX(dp[1][N], dp[2][N])));
  }
}