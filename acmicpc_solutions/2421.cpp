#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int merge(int l, int r) {
  int temp = r, len = 0;
  while (temp) {
    temp /= 10;
    len++;
  }
  for (int i = 0; i < len; i++) {
    l *= 10;
  }
  return l + r;
}
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int N;
  scanf("%d", &N);
  int **dp = new int *[N + 1];
  for (int i = 0; i <= N; i++) {
    dp[i] = new int[N + 1]{0};
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == 1 && i == j) {
        continue;
      }
      dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
      if (isPrime(merge(i, j))) {
        dp[i][j]++;
      }
    }
  }
  printf("%d", dp[N][N]);

  for (int i = 0; i <= N; i++) {
    delete[] dp[i];
  }
  delete[] dp;
}