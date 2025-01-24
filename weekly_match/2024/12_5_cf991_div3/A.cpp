#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> str(n);
    for (string &s: str) {
        cin >> s;
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += str[i].size();
        if (num > m) {
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}