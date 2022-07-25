/*
 * 1239 차트
 * 실버I
 */

#include <iostream>
#pragma warning(disable:4996)
int N, arr[16]{ 0 }, max = 0;

void swap(int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void perm(int depth, int targetNum) {

    if (depth == targetNum - 1) {
        int count = 0;
        for (int i = N; i < N * 2; i++) {
            arr[i] = arr[i-N];
        }
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = i; j < N * 2; j++) {
                sum += arr[j];
                if (sum == 50) {
                    count++;
                }
                if (sum >= 50) {
                    break;
                }
            }
        }
        if (count > max) {
            max = count;
        }
        return;
    }
    for (int i = depth; i < N; i++) {
        swap(i, depth);
        perm(depth + 1, targetNum);
        swap(i, depth);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    perm(0, N);
    
    printf("%d", max/2);
}