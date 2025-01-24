#include <bits/stdc++.h>

using namespace std;

/*
 * P5733 【深基6.例1】自动修正
 * */

int main() {
    int q;
    string str;
    cin >> q >> str;
    while (q--) {
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                string s;
                cin >> s;
                str += s;
                cout << str << endl;
                break;
            }
            case 2: {
                int a, b;
                cin >> a >> b;
                str = str.substr(a, b);
                cout << str << endl;
                break;
            }
            case 3: {
                int a;
                string s;
                cin >> a >> s;
                str.insert(a, s);
                cout << str << endl;
                break;
            }
            case 4: {
                string s;
                cin >> s;
                str.find(s) == string::npos ? cout << -1 : cout << str.find(s);
                cout << endl;
                break;
            }

        }
    }
}