#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n, 0);
    string op;
    int l, r, k;
    while (m--) {
        cin >> op;
        if (op == "water") {
            cin >> l >> r;
            for (int i = l; i <= r; ++i) {
                h[i]++;
            }
        } else if (op == "rise") {
            cin >> l >> r >> k;
            int ans = 0;
            for (int i = l; i <= r; ++i) {
                if (h[i] >= k) {
                    ans++;
                    h[i] = 0;
                }
            }
            cout << ans << endl;
        }


    }

}

int main() {
    solve();
    return 0;
}