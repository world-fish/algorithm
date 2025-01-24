#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        ++m[temp];
        s.insert(temp);
    }
    if (n % 2 != 0 || s.size() != 2) {
        cout << "No" << endl;
        return;
    }
    for (auto item: m) {
        if (item.second != n / 2) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}