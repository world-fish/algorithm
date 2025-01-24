#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string ch;
    cin >> ch;
    ch = " " + ch;
    unordered_set<int> s;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (s.count(ch[i])) ans = max(ans, n - i + 1);
        s.insert(ch[i]);
    }
    s = unordered_set<int>();
    for (int i = n; i > 1; --i) {
        if (s.count(ch[i])) ans = max(ans, i);
        s.insert(ch[i]);
    }
    cout << ans << endl;
    return 0;
}