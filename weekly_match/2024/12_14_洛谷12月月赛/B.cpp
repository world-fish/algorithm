#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<ll> result;
    vector<ll> current_group;
    ll min_val = n + 1;

    for (ll i = n - 1; i >= 0; --i) {
        if (p[i] <= min_val) {
            current_group.push_back(p[i]);
            min_val = p[i];
        } else {
            sort(current_group.begin(), current_group.end(), greater<ll>());
            result.insert(result.end(), current_group.begin(), current_group.end());
            current_group.clear();
            current_group.push_back(p[i]);
            min_val = p[i];
        }
    }

    sort(current_group.begin(), current_group.end(), greater<ll>());
    result.insert(result.end(), current_group.begin(), current_group.end());

    for (ll i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}