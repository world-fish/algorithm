#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    for (vector<int> &i: vec) {
        for (int &j: i) {
            cin >> j;
        }
        sort(i.begin(), i.end());
    }

    vector<int> order(n, -1);
    unordered_set<int> seen;

    for (int i = 0; i < n; ++i) {
        if (seen.count(vec[i][0]) == 0 && vec[i][0] >= 0 && vec[i][0] < n) {
            order[vec[i][0]] = i;
            seen.insert(vec[i][0]);
        } else {
            cout << -1 << endl;
            return;
        }

        for (int j = 1; j < m; ++j) {
            if (vec[i][j] - vec[i][j - 1] != n) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i: order) {
        if (i == -1) {
            cout << -1 << endl;
            return;
        }
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}