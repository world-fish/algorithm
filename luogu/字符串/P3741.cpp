#include <bits/stdc++.h>

using namespace std;

/*
 * P3741 小果的键盘
 * */

int main() {
    int t;
    string str;
    cin >> t >> str;
    int ans = 0;
    string vk = "VK";
    size_t pos = str.find(vk);
    while (pos != string::npos) {
        ans++;
        str[pos] = 'x';
        str[pos + 1] = 'x';
        pos = str.find(vk);
    }
    if (str.find("VV") != string::npos || str.find("KK") != string::npos) ans++;
    cout << ans << endl;
}