#include <bits/stdc++.h>

using namespace std;

/*
 * P1914 小书童——凯撒密码
 * */
char op;

void solve() {
    string temp;
    int a, b;
    cin >> temp;
    if (temp[0] <= 'z' && temp[0] >= 'a') {
        op = temp[0];
        cin >> a >> b;
    } else {
        a = stoi(temp);
        cin >> b;
    }
    string s;
    switch (op) {
        case 'a':
            s = to_string(a) + "+" + to_string(b) + "=" + to_string(a + b);
            cout << s << endl << s.length() << endl;
            break;
        case 'b':
            s = to_string(a) + "-" + to_string(b) + "=" + to_string(a - b);
            cout << s << endl << s.length() << endl;
            break;
        case 'c':
            s = to_string(a) + "*" + to_string(b) + "=" + to_string(a * b);
            cout << s << endl << s.length() << endl;
            break;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}