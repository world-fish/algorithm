#include<bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (a + b >= k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    if (a + c >= k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    if (b + c >= k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}

int main() {
    solve();
    return 0;
}