#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    ll result = 0;

    if (k == 1) {
        ll x_min = max(l1, l2);
        ll x_max = min(r1, r2);
        result = max(0LL, x_max - x_min + 1);
        cout << result << endl;
        return;
    }

    for (ll n = 0;; ++n) {
        ll power = pow(k, n);
        if (power > r2) break;

        ll x_min = max(l1, (l2 + power - 1) / power);
        ll x_max = min(r1, r2 / power);

        if (x_min <= x_max) {
            result += (x_max - x_min + 1);
        }
    }

    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}