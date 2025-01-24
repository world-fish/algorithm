#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 1; i < n; ++i) {
        pair<int, int> temp = {i, n - 1};
        vec.push_back(temp);
    }
    cout << vec.size() << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}