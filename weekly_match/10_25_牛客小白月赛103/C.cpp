#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
    ll n;
    cin >> n;
    if (n <= 2) {
        cout << 1 << endl;
        return;
    }

    ll k = 1;
    while (n > k) {
        k *= 2;
    }
    cout << k << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}