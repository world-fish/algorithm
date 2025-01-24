#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    string str;
    cin >> str;

    int sum = 0;
    int two = 0, three = 0;
    for (char ch: str) {
        if (ch == '2') two++;
        else if (ch == '3') three++;
        sum += ch - '0';
    }
    if (sum % 9 == 0) {
        cout << "YES" << endl;
        return;
    }

    int remainder = sum % 3;
    if (remainder == 1) {
        if (two < 1) {
            cout << "NO" << endl;
            return;
        }
        two--;
    } else if (remainder == 2) {
        if (two < 2) {
            cout << "NO" << endl;
            return;
        }
        two -= 2;
    }
    sum /= 3;
    sum += remainder;
    remainder = sum % 3;
    if (remainder == 1) {
        if (three * 6 + two * 2 < 6) {
            cout << "NO" << endl;
            return;
        }
    } else if (remainder == 2) {
        if (three * 6 + two * 2 < 12) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}