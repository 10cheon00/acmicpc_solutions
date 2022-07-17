#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int main() {
    int N, M, B, high = 1, low = 500, time = 2147483647;
    scanf("%d %d %d", &N, &M, &B);
    int arr[257]{ 0, }; //블럭의 높이가 등장한 횟수

    int n;
    for (int i = 0; i < N * M; i++) {
        scanf("%d", &n);
        arr[n]++;
        if (n < low) {
            low = n;
        }
        if (n > high) {
            high = n;
        }
    }
    int height = low, res, blocks;
    for (int i = low; i <= high; i++) {
        res = 0;
        blocks = 0;
        for (int j = 0; j < 257; j++) {
            if (arr[j]) {
                if (j < i) { // j높이가 i높이보다 작을 경우
                    res += arr[j] * (i - j); // 1초 * 블럭갯수 * 차이
                    blocks += arr[j] * (i - j);
                }
                else if (j > i) { // j높이가 i높이보다 높을 경우
                    res += arr[j] * 2 * (j - i); // 2초 * 블럭개수 * 차이
                    blocks -= arr[j] * (j - i);
                }
            }
        }
        if (B - blocks >= 0 && res <= time) {
            height = i;
            time = res;
        }
    }
    printf("%d %d", time, height);
}