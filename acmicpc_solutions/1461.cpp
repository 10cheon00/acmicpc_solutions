/*
 * 1461 도서관
 * 골드V
 */
#include <iostream>
#define ABS(X) ((X) > 0 ? (X) : -(X))
int main() {
  int N, M, arr[50]{0}, positiveStartIndex = 0;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] < 0) {
      positiveStartIndex++;
    }
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  int dist = 0;
  for (int i = N - 1; i >= positiveStartIndex; i -= M)
    dist += arr[i] * 2;
  for (int i = 0; i < positiveStartIndex; i += M)
    dist += ABS(arr[i]) * 2;

  int max = 0;
  for (int i = 0; i < N; i++) {
    max = ABS(arr[i]) > max ? ABS(arr[i]) : max;
  }
  dist -= max;
  printf("%d", dist);
}
/*
11까지 간다고 생각하면 가는 길에 M-1개만큼의 책을 돌려 놓는다.
그럼 제일 먼 위치 부터 M개씩 없애고 간 거리의 *2만큼을 더한다.
그런데 마지막에 0으로 돌아올 필요는 없다고 한다.
따라서 제일 먼 거리를 마지막에 가면 돌아오는 거리를 줄일 수 있다.
단, 제일 먼 거리가 양수라면, 절대 음수위치로 향하면 안된다.
이동 거리가 더 멀어지기 때문이다. 반대의 경우도 그렇다.
따라서 제일 먼 위치가 양수라면 양수 위치의 책들만 들고 가고,
음수라면 음수 위치의 책들만 들고간다.

여기서 좀만 더 생각해보면... 어차피 양수값끼리 묶고, 음수값끼리 묶기 때문에...
M개씩 지워가면 된다.

-1 3 4 5 6 11
11*2   = 22
5*2    = 10
3*2    = 6
1*2    = 2
max    = 11
-----------
         40 - 11 = 29
*/