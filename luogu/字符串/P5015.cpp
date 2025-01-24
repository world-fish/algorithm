#include <bits/stdc++.h>

using namespace std;

/*
 * P5015 [NOIP2018 普及组] 标题统计
 * */

int main() {
    string s;
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    cout << s << endl;
    cout << s.length();
}