/*
 * 1354 무한수열2
 * 골드IV
 */
#include <iostream>
#include <unordered_map>
using namespace std;
#pragma warning(disable:4996)
long long N, P, Q, X, Y;
unordered_map<long long, long long>dp;

long long calc(long long key) {
    if (key <= 0) {
        return 1;
    }
    if (dp.find(key) != dp.end()) {
        return dp[key];
    }
    long long val = calc(key / P - X) + calc(key / Q - Y);
    dp.insert(pair<long long, long long>(key, val));
    return val;
}

int main() {
    scanf("%lld %lld %lld %lld %lld", &N, &P, &Q, &X, &Y);
    printf("%lld", calc(N));
}