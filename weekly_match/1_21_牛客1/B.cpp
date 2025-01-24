#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> in(n + 1);
    vector<vector<int>> out(n + 1);
    int start = -1, end = -1;
    for (int i = 0; i < n - 1; ++i) {
        int ii, oo;
        cin >> ii >> oo;
        in[ii].push_back(oo);
        out[oo].push_back(ii);
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i].size() == 0 && out[i].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        if (in[i].size() == 0) {
            start = i;
        } else if (in[i].size() > 1) {
            cout << -1 << endl;
            return 0;
        }
        if (out[i].size() == 0) {
            end = i;
        } else if (out[i].size() > 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << start << " " << end << endl;
    return 0;
}