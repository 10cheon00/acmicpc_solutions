/*
0 x
1 1                                 0
2 01                                1
3 1001                              1
4 01101001                          3 = 1 + (1-0) + 1 = 3
5 1001011001101001                  5 = 1 + (3-1) + 3 = 6
6 01101001100101101001011001101001 11 = 3 + (5-3) + 5 = 10
7 1001011001101001011010011001011001101001100101101001011001101001
                                   21 = 5 + (11-5) + 11 = 22
=> 직전전 패턴 + (직전 패턴 - 직전전 패턴) + 직전 패턴 + 1 - N%2*2
=> 직전 패턴 + 직전 패턴 + 1 - N%2*2
*/
#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int dp[1001][1001]{0};
int len[1001]{1, 1, 1};

void decrease(int N) {
  int u = 0;
  dp[N][1]--;
  for (int i = 1; i <= len[N]; i++) {
    if (dp[N][i] < 0) {
      dp[N][i] += 10;
      dp[N][i + 1]--;
    } else {
      break;
    }
  }
}

void increase(int N) {
  int u = 0;
  dp[N][1]++;
  for (int i = 1; i <= len[N]; i++) {
    if (dp[N][i] >= 10) {
      dp[N][i] = 0;
      dp[N][i + 1]++;
    } else {
      break;
    }
  }
}

int main() {
  int N;
  dp[0][1] = dp[1][1] = 0;
  dp[2][1] = 1;
  scanf("%d", &N);
  for (int i = 3; i <= N; i++) {
    int u = 0, d;
    len[i] = len[i - 1] + (dp[i - 1][len[i - 1]] > 4);
    for (int j = 1; j <= len[i]; j++) {
      d = dp[i - 1][j] * 2 + u;
      dp[i][j] = d % 10;
      u = d / 10;
    }
    if (i % 2) {
      decrease(i);
    } else {
      increase(i);
    }
  }
  for (int i = len[N]; i > 0; i--)
    printf("%d", dp[N][i]);
}