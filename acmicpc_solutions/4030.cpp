#include <cmath>
#include <iostream>
int main() {
  for (int cases = 1;; cases++) {
    int A, B, cnt = 0;
    scanf("%d %d", &A, &B);
    if (!A && !B) {
      return 0;
    }

    for (int i = 1, j = 2; i + 1 < B; i += j++) {
      int d = sqrt(i + 1);
      if (i >= A && d * d == i + 1) {
        cnt++;
      }
    }

    printf("Case %d: %d\n", cases, cnt);
  }
}