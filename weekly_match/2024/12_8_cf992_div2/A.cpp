#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &v: arr) {
        cin >> v;
    }
    bool b;
    for (int i = 0; i < arr.size(); ++i) {
        b = false;
        for (int j = 0; j < arr.size(); ++j) {
            if (i == j) continue;
            if (abs(arr[i] - arr[j]) % k == 0) {
                b = true;
            }
        }
        if (b == false) {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}