/*
 * 2157 여행
 * 골드IV
 */

/*
### testcase ###
5 4 6
1 2 2
1 3 5
2 3 4
2 4 5
3 4 1
4 5 3

3 3 3
1 3 5
1 2 2
2 3 2

6 3 4
1 5 4
5 6 8
1 3 9
3 6 1
##########

dp[i][j] = i번째 도시까지 최대 j개의 도시를 경유해 방문했을 때 기내식의
최대만족도

6번째 도시까지 최대 3번을 경유하여 갔을 때 가능한 경로는 이렇다.
1->6,
1->2->6, 1->3->6, 1->4->6, 1->5->6
일단 방문한 횟수가 다른 경우를 생각하면 점화식은 이렇다.
result = MAX(dp[i][j], dp[i][j-1])

방문한 횟수를 고정했을 때 최대 만족도를 찾기 위해 도착할 도시를 떼어내본다.
1->2, 1->3, 1->4, 1->5
dp[6][3] = MAX(
  dp[2][2] + food[2][6],
  MAX(
    dp[3][2] + food[3][6],
    MAX(
      dp[k][j-1] + food[k][i],  <-- 단, (2≤k≤i)
      ...
      MAX(
        dp[6][j-1] + food[6][6]
      )
    )
  )
)
예외로, dp[5][2]처럼 1번 도시에서 5번 도시로 갈 때는 위 점화식이 안 먹힌다.
dp[5][2] =  MAX(
  dp[2][1] + food[2][5],  <-- 2번 도시에서 5번 도시로 가는 경로를 더하고 있다!
  MAX(
    dp[3][1] + food[3][5],  <-- 3번 도시에서 5번 도시로 가는 경로를 더하고 있다!
    MAX(
      ...
    )
)
이런 경우는 1번 도시에서 5번 도시로 가는 경로를 바로 대입해준다.

또 주의할 점은 dp에 값이 들어 있지만 경로가 없을 경우 또는 경로는 있지만 dp에
값이 없을 경우다. 왔던 길과 새로운 길이 모두 있어야 경로를 탐색할 수 있다.

반복자가 i, j, k 총 3개가 나오기 때문에 3중 반복을.. 돌려야 한다.
*/
#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
int main() {
  int N, M, K, food[301][301]{0}, dp[301][301]{0};
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i <= K; i++) {
    int from, to, num;
    scanf("%d %d %d", &from, &to, &num);
    if (from < to && food[from][to] < num) {
      food[from][to] = num;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 2; j <= i; j++) {
      if (j == 2) {
        dp[i][j] = food[1][i];
      } else {
        dp[i][j] = dp[i][j - 1];
        for (int k = 2; k <= i; k++) {
          if (dp[k][j - 1] && food[k][i])
            dp[i][j] = MAX(dp[k][j - 1] + food[k][i], dp[i][j]);
        }
      }
    }
  }
  printf("%d", dp[N][M]);
}
