#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e6 + 10;
char buf[N];
ll n;

bool check_1100(ll i) {
    if (i < 0 || i >= n - 3) return false;
    if (buf[i] == '1' && buf[i + 1] == '1' && buf[i + 2] == '0' && buf[i + 3] == '0') return true;
    return false;
}

void solve() {
    cin >> buf;
    n = strlen(buf);
    ll count = 0;
    for (ll i = 0; i < n; ++i) {
        if (check_1100(i)) count++;
    }
    int q;
    cin >> q;
    while (q--) {
        int i;
        char v;
        cin >> i >> v;
        i--;
        if (buf[i] != v) {
            bool before = check_1100(i) || check_1100(i - 1) || check_1100(i - 2) || check_1100(i - 3);
            buf[i] = v;
            bool after = check_1100(i) || check_1100(i - 1) || check_1100(i - 2) || check_1100(i - 3);
            count += after - before;
        }
        cout << (count ? "YES" : "NO") << endl;
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) solve();

}