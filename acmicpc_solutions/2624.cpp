/*
 * 2624 ���� �ٲ��ֱ�
 * ���V

 11
 3
 1 5
 3 2
 5 2
    | 0  1  2  3  4  5  6  7  8  9 10 11
 ---+-----------------------------------
  1 | 1  1  1  1  1  1  0  0  0  0  0  0
  3 | 1  1  1  2  2  2  2  2  2  1  1  1
  5 | 1  1  1  2  2  3  3  3  4  3  4  4

 ���������� ����.
 ���� ������ �ɸ� ������ ������ �� �־��� �������� ���� ������ �ʵ��� �ؾ� �Ѵ�.
 1, 3�� ¥���� 8���� ����ٰ� �� �� 3���� 2���� �־��� �����ϱ� ������ ��츦 ��� ���ϸ�
 �ȴ�. 1�� ¥���� 8�� ����� ����� �� + 1�� ¥�� 5���� 3�� ¥�� 1���� ����� ����� ��
 + 1�� ¥�� 2���� 3�� ¥�� 2���� ����� ����� �� ���� ��ġ�� ������ ���� �ʴ� ���
 ���� �ִ� �������� ���� ����� ���� ��� ���ؾ� �Ѵ�.

 1, 3, 5�� ¥���� 10���� ����� ����� ���� 4��.
 5�� ¥�� 0��) 1, 3�� ¥���� 10���� ����� ����� �� = 1
 5�� ¥�� 1��) 1, 3�� ¥���� 10-5=5���� ����� ����� �� = 2
 5�� ¥�� 1��) 1, 3�� ¥���� 10-10=0���� ����� ����� �� = 1
 �� ������ ��ġ�� 4���� ���´�.
 */
#include <iostream>
int main() {
  int T, K, value[101], count[101];
  scanf("%d %d", &T, &K);
  int **dp = new int *[K + 1];
  dp[0] = new int[T + 1]{0};
  for (int i = 1; i <= K; i++) {
    int P, N;
    scanf("%d %d", &P, &N);
    value[i] = P;
    count[i] = N;
    dp[i] = new int[T + 1]{0};
  }
  dp[0][0] = 1;
  for (int i = 1; i <= K; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= T; j++) {
      for (int k = 0; k <= count[i]; k++) {
        if (j < value[i] * k)
          break;
        dp[i][j] += dp[i - 1][j - value[i] * k];
      }
      printf("%3d", dp[i][j]);
    }
    puts("");
  }
  printf("%d", dp[K][T] ? dp[K][T] : 0);
}
