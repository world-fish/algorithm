#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

vector<ll> preprocess_f(int limit) {
    vector<ll> f(limit + 1, 0);
    for (int x = 1; x <= limit; ++x) {
        int numerator = 0, denominator = x, steps = 0;
        while (numerator != denominator) {
            if (numerator < denominator) {
                numerator++;
            } else {
                numerator++;
                denominator++;
            }
            int g = gcd(numerator, denominator);
            numerator /= g;
            denominator /= g;
            steps++;
        }
        f[x] = steps;
    }
    return f;
}

ll sum_f(ll n, const vector<ll> &pre_f) {
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        res = (res + pre_f[i]) % MOD;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;

    if (n <= 1000000) {
        auto pre_f = preprocess_f(n);
        cout << sum_f(n, pre_f) << endl;
    } else {
        cout << "未实现大规模 n 的优化逻辑" << endl;
    }

    return 0;
}