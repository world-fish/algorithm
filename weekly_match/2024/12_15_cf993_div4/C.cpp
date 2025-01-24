#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int one = min(m, a);
    int two = min(m, b);
    int three = min((m - one) + (m - two), c);
    cout << one + two + three << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}