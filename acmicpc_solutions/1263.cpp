/*
 * 1263 시간관리
 * 실버I
 */
#include <iostream>
struct Schedule{
    int T, S;
}; 
Schedule* arr;

void quickSort(int left, int right) {
    if (left > right) {
        return;
    }
    int i = left, j = right;
    int pivot = arr[left].S;
    while (i <= j) {
        while (arr[i].S > pivot) {
            i++;
        }
        while (arr[j].S < pivot && i < j) {
            j--;
        }
        if (i < j) {
            Schedule t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    Schedule t = arr[left];
    arr[left] = arr[j];
    arr[j] = t;
    quickSort(left, j);
    quickSort(j + 1, right);
}

int main() {
    int N;
    scanf("%d", &N);
    arr = new Schedule[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].T, &arr[i].S);
    }
    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i].S > arr[j].S) {
                Schedule t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    int time = arr[N - 1].S;
    for (int i = N - 1; i >= 0; i--) {
        if (time > arr[i].S) {
            time = arr[i].S;
        }
        time -= arr[i].T;
    }
    if (time < 0) {
        printf("-1");
    }
    else {
        printf("%d", time);
    }


    delete[] arr;
}