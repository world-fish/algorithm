#include <bits/stdc++.h>

using namespace std;

void block(vector<vector<int>> &arr, int x, int y, int power) {
    if (power <= 0) {
        return;
    } else {
        for (int i = x; i < x + power; i++) {
            fill_n(arr[i].begin() + y, power, 0);
        }
        if (power >= 2) {
            int halfPower = power / 2;
            block(arr, x + power, y, halfPower);
            block(arr, x, y + power, halfPower);
            block(arr, x + power, y + power, halfPower);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(1 << n, vector<int>(1 << n, 1));
    block(arr, 0, 0, 1 << (n - 1));
    for (vector<int> vec: arr) {
        for (int i: vec) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}