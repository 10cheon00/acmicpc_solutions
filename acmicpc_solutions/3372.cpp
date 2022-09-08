/*
 * 3372 보드점프
 * 실버I
 */
#include <iostream>
class BigInt {
public:
  int size;
  int arr[100];
  BigInt() { size = 0; }
  BigInt &operator+=(BigInt &bInt) {
    int up = 0, digit, i = 0;
    while (1) {
      digit = 0;
      if (i < bInt.size) {
        digit += bInt.arr[i];
      }
      if (i < this->size) {
        digit += this->arr[i];
      }
      if (i < this->size) {
        this->arr[i] = (up + digit) % 10;
      } else {
        this->push_back((up + digit) % 10);
      }
      up = (up + digit) / 10;
      i++;
      if (i >= this->size && i >= bInt.size && !up) {
        break;
      }
    }
    return *this;
  }
  void push_back(int n) { this->arr[this->size++] = n; }
};
int arr[100][100];
BigInt dp[100][100];
int main() {
  int N;
  scanf("%d", &N);
  dp[0][0].push_back(1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &arr[i][j]);
      if (arr[i][j]) {
        if (j + arr[i][j] < N) {
          dp[i][j + arr[i][j]] += dp[i][j];
        }
        if (i + arr[i][j] < N) {
          dp[i + arr[i][j]][j] += dp[i][j];
        }
      }
    }
  }
  if (dp[N - 1][N - 1].size == 0) {
    printf("0");
  } else {
    for (int i = dp[N - 1][N - 1].size - 1; i >= 0; i--) {
      printf("%d", dp[N - 1][N - 1].arr[i]);
    }
  }
}