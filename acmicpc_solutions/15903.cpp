/*
 * 15903 카드 합체 놀이
 * 실버I
 */
#include <iostream>
#include <queue>
using namespace std;
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  priority_queue<long long, vector<long long>, greater<long long>> list;
  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);
    list.push(num);
  }
  for (int i = 0; i < M; i++) {
    long long x = list.top();
    list.pop();
    long long y = list.top();
    list.pop();
    list.push(x + y);
    list.push(x + y);
  }
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += list.top();
    list.pop();
  }
  printf("%lld", sum);
}