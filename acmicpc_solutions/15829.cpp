#include <iostream>
#define M 1234567891
int main() {
  char str[51];
  int N;
  scanf("%d", &N);
  scanf("%s", str);
  long long mult = 1, hash = 0;
  for (int i = 0; str[i]; i++) {
    hash = (hash + (str[i] - 'a' + 1) * mult) % M;
    mult = mult * 31 % M;
  }
  printf("%lld", hash);
}