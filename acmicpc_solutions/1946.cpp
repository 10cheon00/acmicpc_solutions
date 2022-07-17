#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

struct D{
    int first, second;
};

bool identifier(const D& a, const D& b) {
    return a.first < b.first;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N;
        vector<D> arr;
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            D d;
            scanf("%d %d", &d.first, &d.second);
            arr.push_back(d);
        }

        sort(arr.begin(), arr.end(), &identifier);

        int count = 0, high = 100001;
        for (int j = 0; j < N; j++) {
            if (arr[j].second < high) {
                high = arr[j].second;
                count++;
            }
        }
        printf("%d\n", count);
    }
}