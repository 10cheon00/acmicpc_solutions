/*
 * 떡 먹는 호랑이
 * 실버I
1  a
2  b
3  a+b
4  a+b+b
5  a+b+b+a+b
6  a+b+b+a+b+a+b+b = 3A+5B
7  a+b+b+a+b+a+b+b+a+b+b+a+b = 5A+8B
  = fibonacci(D-1) * A + fibonacci(D-2) * B
*/
#include <iostream>
int dp[32]{0, 1}, A = 0, B = 0;
int main() {
  int D, K;
  for (int i = 2; i < 32; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  scanf("%d %d", &D, &K);
  for (int i = 1; i <= K / 2; i++) {
    if ((K - dp[D - 2] * i) % dp[D - 1] == 0) {
      A = i;
      B = (K - dp[D - 2] * i) / dp[D - 1];
      break;
    }
  }
  printf("%d\n%d", A, B);
}