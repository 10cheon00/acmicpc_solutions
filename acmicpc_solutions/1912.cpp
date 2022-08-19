/*
 * 1912 연속합
 * 실버II
 */
#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int main() {
  int N, arr[100001]{0}, dp[100001]{0};
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
  }
  int max = -1001;
  for (int i = 1; i <= N; i++) {
    dp[i] = MAX(arr[i], dp[i - 1] + arr[i]);
    printf("%3d", dp[i]);
    if (max < dp[i]) {
      max = dp[i];
    }
  }
  puts("");
  printf("%d", max);
}