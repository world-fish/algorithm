#include <bits/stdc++.h>

using namespace std;

/*
 * P1765 手机
 * */

int main() {
    string str;
    getline(cin, str);
    int num[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

    int ans = 0;
    for (char ch: str) {
        if (ch == ' ') {
            ans++;
            continue;
        }
        ans += num[ch - 'a'];
    }
    cout << ans << endl;
}