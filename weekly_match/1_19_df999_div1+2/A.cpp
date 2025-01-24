#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    bool b = false;
    int sum = 0;
    int num;
    while (n--) {
        cin >> num;
        if (num % 2 == 0) {
            b = true;
        } else {
            sum++;
        }
    }
    cout << (b ? ++sum : --sum) << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}