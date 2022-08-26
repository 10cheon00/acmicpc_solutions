/*
 * 2205 저울 추 만들기
 * 실버I
 */
#include <iostream>
int main() {
  int N, tin[10001]{0}, lead[10001]{0},
      arr[16]{0,   2,   4,    8,    16,   32,   64,    128,
              256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
  scanf("%d", &N);
  int max = 0;
  while (arr[max++] < N)
    ;
  for (int i = N; i > 0; i--) {
    for (int j = max; j > 0; j--) {
      if (arr[j] - i <= N && !tin[arr[j] - i]) {
        tin[arr[j] - i] = 1;
        lead[i] = arr[j] - i;
        break;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    printf("%d\n", lead[i]);
  }
}