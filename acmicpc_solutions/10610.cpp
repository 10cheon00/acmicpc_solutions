/*
 * 10610 30
 * ½Ç¹öIV
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define atoi(X) (X) - '0'

int main() {
    char str[100001];
    cin >> str;
    int len = strlen(str);
    vector<int> arr;
    for (int i = 0; i < len; i++) {
        arr.push_back(atoi(str[i]));
    }
    sort(arr.begin(), arr.end(), greater<int>());
    if (arr[len - 1] != 0 || arr.size() == 0) {
        cout << -1;
    }
    else {
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += arr[i];
        }
        if (sum % 3 == 0) {
            for (int i = 0; i < len; i++) {
                cout << arr[i];
            }
        }
        else {
            cout << -1;
        }
    }
}