#include<bits/stdc++.h>

using namespace std;

void solve() {
    int type, a, b, c, d;
    cin >> type >> a >> b >> c >> d;
    int ans = 0;
    if (type == 0) {
        ans = a + b;
    } else if (type == 1) {
        ans = max(a - c, 0) + max(b - d, 0);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}