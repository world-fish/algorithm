#include <bits/stdc++.h>

using namespace std;

/*
 * P1200 [USACO1.1] 你的飞碟在这儿 Your Ride Is Here
 * */

int main() {
    string comet, group;
    cin >> comet >> group;
    int c = 1, g = 1;
    for (char ch: comet) {
        c *= ch - 'A' + 1;
        c %= 47;
    }
    for (char ch: group) {
        g *= ch - 'A' + 1;
        g %= 47;
    }
    if (c == g) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    return 0;
}