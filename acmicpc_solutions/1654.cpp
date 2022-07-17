#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int main() {
    int K, N, arr[10000], high = 0, len = 0;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
        len += arr[i];
    }
    int count;
    len /= N;
    for (int i = 1; i <= len; i++) {
        count = 0;
        for (int j = 0; j < K; j++) {
            count += arr[j] / i;
        }
        if (N <= count && high < i) {
            high = i;
        }
    }
    printf("%d", high);
}