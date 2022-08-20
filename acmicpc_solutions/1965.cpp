#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int main() {
  int N, arr[1001], dp[1001]{0}, ans = 0;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i <= N; i++) {
    for (int j = i; j >= 0; j--) {
      if (arr[i] > arr[j]) {
        dp[i] = MAX(dp[j] + 1, dp[i]);
      }
    }
    ans = MAX(ans, dp[i]);
  }
  printf("%d", ans);
}