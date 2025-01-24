#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string str;
    cin >> str;
    for (char &ch: str) {
        if (ch == 'p') ch = 'q';
        else if (ch == 'q') ch = 'p';
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}