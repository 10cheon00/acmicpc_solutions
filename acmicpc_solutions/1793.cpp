/*
 * 타일링
 * 실버II
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
std::map<int, vector<int>> dp;
vector<int> sum(vector<int> str1, vector<int> str2) {
  int maxLen = str1.size() > str2.size() ? str1.size() : str2.size();
  bool upper = false;
  vector<int> res;
  for (int i = 0; i < maxLen; i++) {
    int left = i < str1.size() ? str1[i] : 0,
        right = i < str2.size() ? str2[i] : 0;
    res.push_back((upper + left + right) % 10);
    upper = (upper + left + right) / 10;
  }
  if (upper) {
    res.push_back(upper);
  }
  return res;
}

vector<int> f(int N) {
  if (dp.find(N) == dp.end()) {
    dp[N] = sum(f(N - 1), sum(f(N - 2), f(N - 2)));
  }
  return dp[N];
}
int main() {
  int N;
  dp[0] = vector<int>{1};
  dp[1] = vector<int>{1};
  while (scanf("%d", &N) > 0) {
    vector<int> res = f(N);
    for (auto i = res.rbegin(); i != res.rend(); i++)
      printf("%d\n", *i);
  }
}