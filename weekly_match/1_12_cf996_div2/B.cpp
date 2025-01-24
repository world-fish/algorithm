#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll sum_a = 0, sum_b = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    if (sum_a < sum_b) {
        cout << "NO" << endl;
        return;
    }

    bool possible = true;
    int minn = INT_MAX;
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            temp = b[i] - a[i];
            if (possible) {
                possible = false;
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            minn = min(minn, (int) (a[i] - b[i]));
        }
    }
    if (minn >= temp) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
