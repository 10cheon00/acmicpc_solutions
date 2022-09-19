#include <iostream>
int main() {
  int A, B, L, S[50], N;
  scanf("%d", &L);
  for (int i = 0; i < L; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &N);
  int below = 0, above = 1000;
  for (int i = 0; i < L; i++) {
    if (S[i] > N) {
      above = above > S[i] ? S[i] : above;
    } else if (S[i] < N) {
      below = below < S[i] ? S[i] : below;
    } else {
      printf("0");
      return 0;
    }
  }
  printf("%d", (N - below) * (above - N) - 1);
}