#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
    int ans = 1, maxVal = a[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > maxVal) {
            maxVal = a[i];
            ans++;
        }
    }
    cout << ans << endl;

}

int main() {
    solve();

    return 0;
}