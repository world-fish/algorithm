#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll ans;
    vector<ll> vec(n);
    for (ll &l: vec) {
        cin >> l;
    }
    sort(vec.begin(), vec.end());
    if (vec[0] == 1) {
        cout << -1 << endl;
        return;
    }
    cout << 100000000000001921 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}