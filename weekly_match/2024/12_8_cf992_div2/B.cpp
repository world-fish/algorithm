#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 1, count = 1;
    while (sum < n) {
        count++;
        sum++;
        sum *= 2;
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}