/*
 * 1276 Platforme
 * ½Ç¹ö I
 */
#include <iostream>
struct Platform {
    int y, x1, x2;
};
Platform* arr;

int main() {
    int N;
    scanf("%d", &N);
    arr = new Platform[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &arr[i].y, &arr[i].x1, &arr[i].x2);
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i].y < arr[j].y) {
                Platform p = arr[i];
                arr[i] = arr[j];
                arr[j] = p;
            }
        }
    }

    int length = 0;
    for (int i = 0; i < N; i++) {
        int j = i + 1;
        while (j < N) {
            if (arr[j].x1 <= arr[i].x1 && arr[i].x1 < arr[j].x2) {
                length += arr[i].y - arr[j].y;
                break;
            }
            j++;
        }
        if (j == N) {
            length += arr[i].y;
        }
        j = i + 1;
        while (j < N) {
            if (arr[j].x1 < arr[i].x2 && arr[i].x2 <= arr[j].x2) {
                length += arr[i].y - arr[j].y;
                break;
            }
            j++;
        }
        if (j == N) {
            length += arr[i].y;
        }
    }

    printf("%d", length);

    delete[]arr;
}