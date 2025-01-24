#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> data(n);
    for (string &i: data) {
        cin >> i;
    }
    int u = 0, d = n - 1, l = 0, r = m - 1;
    int sum = 0;
    while (d - u >= 1 && r - l >= 1) {
        string str;
        int x = u, y = l;
        for (int i = l; i <= r; ++i) {
            str.push_back(data[u][i]);
        }
        for (int i = u + 1; i <= d; ++i) {
            str.push_back(data[i][r]);
        }
        for (int i = r - 1; i >= l; i--) {
            str.push_back(data[d][i]);
        }
        for (int i = d - 1; i >= u + 1; i--) {
            str.push_back(data[i][l]);
        }
        str += str.substr(0, 3);

        size_t pos = str.find("1543");
        while (pos != string::npos) {
            sum++;
            pos = str.find("1543", pos + 1);
        }
        u++;
        l++;
        d--;
        r--;
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}