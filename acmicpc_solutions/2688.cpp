/*
 * 2688 줄어들지 않아
 * 실버I
    0   1   2   3   4   5   6   7   8   9
N=1 1   1   1   1   1   1   1   1   1   1
  2 1   2   3   4   5   6   7   8   9  10
  3 1   3   6  10  ..
  4
  5
*/
#include <iostream>
long long dp[65][10]{0};
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < 10; i++) {
    dp[1][i] = 1;
  }
  for (int i = 2; i <= 64; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k <= j; k++) {
        dp[i][j] += dp[i - 1][k];
      }
    }
  }
  for (int i = 0; i < T; i++) {
    int N;
    long long res = 0;
    scanf("%d", &N);
    for (int j = 0; j < 10; j++) {
      res += dp[N][j];
    }
    printf("%lld\n", res);
  }
}