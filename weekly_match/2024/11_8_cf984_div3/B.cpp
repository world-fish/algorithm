#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<long long> a(k);
    map<int, int> myMap;
    while (k--) {
        int b, c;
        cin >> b >> c;
        myMap[b] += c;
    }
    for (auto i: myMap) {
        a.push_back(i.second);
    }
    sort(a.begin(), a.end());
    long long sum = 0;
    while (n--) {
        if (a.empty()) {
            cout << sum << endl;
            return;
        }
        sum += a.back();
        a.pop_back();
    }
    cout << sum << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}