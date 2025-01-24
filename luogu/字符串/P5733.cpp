#include <bits/stdc++.h>

using namespace std;

/*
 * P5733 【深基6.例1】自动修正
 * */

int main() {
    string s;
    cin >> s;
    for (char &c: s) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
    }
    cout << s;
}