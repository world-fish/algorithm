#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int dif = abs(a - b);
    if (dif % 2 == 0) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}