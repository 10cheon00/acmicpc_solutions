#include <iostream>
int main() {
  int N, arr[50001]{0};
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i <= N; i++) {
    if (arr[i - 1] <= arr[i] && arr[i] >= arr[i + 1]) {
      printf("%d\n", i);
    }
  }
}