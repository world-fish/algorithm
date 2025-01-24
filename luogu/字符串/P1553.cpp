#include <bits/stdc++.h>

using namespace std;

/*
 * P1553 数字反转（升级版）
 * */

int main() {
    string str;
    cin >> str;

    if (str.find('.') != string::npos) {
        string s1, s2;
        int pos = str.find('.');
        s1 = str.substr(0, pos++);
        s2 = str.substr(pos);
        reverse(s1.begin(), s1.end());
        s1 = to_string(stoll(s1));
        s2 = to_string(stoll(s2));
        reverse(s2.begin(), s2.end());
        s2 = to_string(stoll(s2));
        str = s1 + '.' + s2;
    } else if (str.find('/') != string::npos) {
        string s1, s2;
        int pos = str.find('/');
        s1 = str.substr(0, pos++);
        s2 = str.substr(pos);
        reverse(s1.begin(), s1.end());
        s1 = to_string(stoll(s1));
        s2 = to_string(stoll(s2));
        reverse(s2.begin(), s2.end());
        s2 = to_string(stoll(s2));
        str = s1 + '/' + s2;
    } else if (str.back() == '%') {
        str = str.substr(0, str.size() - 1);
        reverse(str.begin(), str.end());
        long long i = stoll(str);
        str = to_string(i) + '%';
    } else {
        reverse(str.begin(), str.end());
        str = to_string(stoll(str));
    }
    cout << str;
    return 0;
}