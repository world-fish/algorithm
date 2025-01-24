#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll flag = 0;

int main() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    map<ll, ll> m;
    vector<ll> s;
    ll sum = 0;
    ll ans = 0;

    for (ll &i: vec) {
        cin >> i;
        ++m[i];
        sum += i;
        if (m[i] > 1 || i < 1 || i > n) s.push_back(i);
    }
    if (sum != (n + 1) * n / 2) {
        cout << -1 << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    for (ll i = 1; i <= n; ++i) {
        if (m[i] == 0) {
            ans += abs(s[flag] - i);
            --m[s[flag++]];
        }
    }
    cout << ans / 2 << endl;
    return 0;
}