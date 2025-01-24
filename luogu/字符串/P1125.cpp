#include <bits/stdc++.h>

using namespace std;

/*
 * P1125 [NOIP2008 提高组] 笨小猴
 * */

int main() {
    string s;
    cin >> s;
    int maxn = INT_MIN, minn = INT_MAX;
    map<char, int> mp;
    for (char c: s) {
        mp[c]++;
    }
    for (auto &p: mp) {
        maxn = max(maxn, p.second);
        minn = min(minn, p.second);
    }
    int num = maxn - minn;
    set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    if (primes.find(num) != primes.end()) {
        cout << "Lucky Word" << endl << num;
    } else {
        cout << "No Answer" << endl << 0;
    }


}