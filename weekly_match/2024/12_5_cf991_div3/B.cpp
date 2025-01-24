#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    ll odd = 0, even = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if ((i + 1) % 2 != 0) {
            odd += arr[i];
        } else {
            even += arr[i];
        }
    }

    int nOdd = (n + 1) / 2;
    int nEven = n / 2;

    if (odd % nOdd != 0 || even % nEven != 0 || odd / nOdd != even / nEven || (odd + even) % n != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}