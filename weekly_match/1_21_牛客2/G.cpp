#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 1 << endl;
        return;
    }
    ll sum = m, count = 1;
    ll minn = abs(n - m);
    while (abs(n - sum * m) < minn) {
        sum *= m;
        minn = abs(n - sum);
        ++count;
    }
    cout << count << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}