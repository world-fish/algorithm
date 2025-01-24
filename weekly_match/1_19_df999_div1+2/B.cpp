#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    set<int> s, forS;

    for (int &i: vec) {
        cin >> i;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - 1; ++i) {
        if (vec[i] == vec[i + 1]) {
            forS.insert(vec[i]);
            s.insert(vec[i]);
        }
    }
    int minn;
    pair<int, int> p;
    for (int i: forS) {
        minn = INT_MAX;
        for (int j = 0; j < n - 1; ++j) {
            if (vec[j] == i && s.find(vec[j]) != s.end()) {
                s.erase(vec[j]);
                ++j;
                continue;
            }
            if (vec[j + 1] - vec[j] < minn) {
                if (vec[j + 1] == i && s.find(vec[j + 1]) != s.end()) {
                    if (j + 3 < n) {
                        minn = abs(vec[j + 3] - vec[j]);
                        p.first = vec[j + 3];
                        p.second = vec[j];
                    }
                    continue;
                }
                minn = abs(vec[j + 1] - vec[j]);
                p.first = vec[j + 1];
                p.second = vec[j];
            }
        }
        if (minn < (2 * i)) {
            cout << p.first << " " << p.second << " " << i << " " << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}