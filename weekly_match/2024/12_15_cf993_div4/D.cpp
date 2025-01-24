#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> myMap;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b[0] = a[0];
    myMap[b[0]]++;
    int maxn = myMap[b[0]]++;
    unordered_set<int> mySet;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            int subscript = i;
            while (subscript < n && a[subscript] == a[i]) {
                subscript++;
            }
            if (subscript < n && myMap[a[subscript]] < myMap[a[i]]) {
                b[i] = a[subscript];
            } else {
                b[i] = a[i];
            }
            myMap[b[i]]++;
            maxn = max(maxn, myMap[b[i]]);
        } else {
            if (a[i] == maxn) {
                b[i] = n--;
            } else {
                b[i] = a[i];
            }
            myMap[b[i]]++;
            maxn = max(maxn, myMap[b[i]]);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
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