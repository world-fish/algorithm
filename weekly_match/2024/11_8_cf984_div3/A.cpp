#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "yes" << endl;
        return;
    }
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
    for (int i = 0; i < a.size() - 1; ++i) {
        int temp = abs(a[i] - a[i + 1]);
        if (temp != 5 && temp != 7) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}