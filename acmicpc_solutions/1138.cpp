/*
 * 1138 한 줄로 서기
 * 실버II
 */
#include <iostream>
#pragma warning(disable:4996)

int main() {
    int N, num;
    scanf("%d", &N);
    int* arr = new int[N] {0};
    for (int height = 0; height < N; height++) {
        scanf("%d", &num);
        int count = 0, index = 0;
        while (count < num || arr[index] > 0) {
            if (arr[index] == 0) {
                count++;
            }
            index++;
        }
        arr[index] = height + 1;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    delete[] arr;
}
