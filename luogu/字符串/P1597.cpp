#include <bits/stdc++.h>

using namespace std;

/*
 * P1597 语句解析
 * */

int a, b, c;

void assignment(int &address, char value) {
    switch (value) {
        case 'a':
            address = a;
            break;
        case 'b':
            address = b;
            break;
        case 'c':
            address = c;
            break;
        default:
            address = value - '0';
            break;
    }
}

int main() {
    string str;
    cin >> str;
    vector<string> vec;
    string word;
    for (char ch: str) {
        if (ch == ';') {
            vec.push_back(word);
            word.clear();
        } else {
            word += ch;
        }
    }
    for (string s: vec) {
        switch (s[0]) {
            case 'a':
                assignment(a, s[3]);
                break;
            case 'b':
                assignment(b, s[3]);
                break;
            case 'c':
                assignment(c, s[3]);
                break;
        }
    }
    cout << a << ' ' << b << ' ' << c;

    return 0;
}