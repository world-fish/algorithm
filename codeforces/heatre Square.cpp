#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, m, a;
    cin >> n >> m >> a;
    ll l, w;
    l = (n - 1) / a + 1;
    w = (m - 1) / a + 1;
    cout << l * w << endl;

}

int main() {
    solve();
    return 0;
}