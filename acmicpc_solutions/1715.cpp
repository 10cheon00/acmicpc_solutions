#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
int main() {
    int N, s;
    scanf("%d", &N);
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        scanf("%d", &s);
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end());
    s = 0;
    while (1) {
        vector<int> res;
        int i = 1;
        int last = arr[0] + arr[1];
        s += last;
        if (arr.size() <= 2) {
            break;
        }
        while (1) {
            if (i + 2 < arr.size()) {
                if (last + arr[i + 1] <= arr[i + 1] + arr[i + 2]) {
                    last += arr[i++ + 1];
                }
                else {
                    res.push_back(last);
                    last = arr[i + 1] + arr[i + 2];
                    i += 2;
                }
            }
            else {
                last += arr[i++ + 1];
            }
            s += last;
            if (i >= arr.size() - 1) {
                res.push_back(last);
                break;
            }
        }

        arr = res;
    }
    printf("%d", s);
}