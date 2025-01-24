#include <bits/stdc++.h>

using namespace std;

/*
 * P1598 垂直柱状图
 * */

int main() {
    string str;
    unordered_map<char, int> myMap;
    for (int i = 0; i < 4; i++) {
        getline(cin, str);
        for (char ch: str) {
            myMap[ch]++;
        }
    }
    myMap.erase(' ');
    int maxn = INT_MIN;
    for (auto item: myMap) {
        maxn = max(maxn, item.second);
    }
    for (int i = 0; i < 26; ++i) {
        myMap['A' + i] = maxn - myMap['A' + i];
    }
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (j != 0) cout << ' ';
            if (myMap[char('A' + j)] != 0) {
                myMap[char('A' + j)]--;
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 26; ++i) {
        if (i != 0) cout << ' ';
        cout << char('A' + i);
    }


    return 0;
}