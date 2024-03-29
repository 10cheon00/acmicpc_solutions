// 겉넓이를 구하기 위해 한 블록의 노출된 부분을 찾기보다,
// 더미의 한 면만 바라본다는 느낌으로 생각하면 좋다.
// 각 축을 바라보아 구한 값을 *2하면 겉넓이가 된다.

// 하지만 이 방법은 약간 틀린게, U자형으로 된 기둥?에서 생기는
// 겉넓이의 넓이는 알 방법이 없다.
// 아래에서부터 한 층씩 올라가며 각 정육면체의
// 노출된 영역을 따져야 한다.
// 무슨 짓을 하든지 위에서 본 면과 아래에서 본 면은
// 항상 N*M이다. 따라서 옆면의 개수가 몇 개인지만 가늠한다.

// 층을 올라가면서 모든 정육면체를 검사하기보다,
// 한 좌표마다 정육면체의 겉넓이를 계산하는 방법이 더 적은
// 반복횟수를 가진다.

// 3중 for문을 하지 않고도 가능하다.
// 한 좌표(A)의 높이보다 인접한 다른 좌표(B)의 높이가 더 높을 때
// 서로 붙은 면은 겉넓이에 포함되지 않는다.
// (A)와 (B)가 붙은 면은 밖으로 노출되어있지 않기 때문이다.
// 따라서 한 좌표의 겉넓이를 계산할 때 인접한 좌표들 중에
// 높이가 상대적으로 더 작은 좌표들만 계산한다.
// 어떤 좌표의 한 면의 겉넓이는 높이만큼이다.
// 그러므로, 한 좌표의 높이 - 인접한 좌표의 높이를
// 각 면마다 수행하여 한 좌표의 겉넓이를 구한다.
#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int main() {
  int N, M, map[102][102]{0};
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  int res = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      res += MAX(0, map[i][j] - map[i - 1][j]) +
             MAX(0, map[i][j] - map[i][j - 1]) +
             MAX(0, map[i][j] - map[i][j + 1]) +
             MAX(0, map[i][j] - map[i + 1][j]);
    }
  }
  printf("%d", res + N * M * 2);
}