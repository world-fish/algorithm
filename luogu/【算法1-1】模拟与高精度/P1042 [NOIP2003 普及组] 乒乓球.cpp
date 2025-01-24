#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 * P1042 [NOIP2003 普及组] 乒乓球
 * */

int main() {
    string str;
    int scoreW11 = 0, scoreL11 = 0;
    int scoreW21 = 0, scoreL21 = 0;
    vector<pair<int, int>> vec11;
    vector<pair<int, int>> vec21;
    while (getline(cin, str)) {
        for (char ch: str) {
            if (ch == 'W') {
                scoreW11++;
                scoreW21++;
            } else if (ch == 'L') {
                scoreL11++;
                scoreL21++;
            } else if ('E') {
                break;
            }
            if (scoreW11 >= 11 && scoreW11 - scoreL11 >= 2 || scoreL11 >= 11 && scoreL11 - scoreW11 >= 2) {
                vec11.push_back({scoreW11, scoreL11});
                scoreW11 = 0, scoreL11 = 0;
            }
            if (scoreW21 >= 21 && scoreW21 - scoreL21 >= 2 || scoreL21 >= 21 && scoreL21 - scoreW21 >= 2) {
                vec21.push_back({scoreW21, scoreL21});
                scoreW21 = 0, scoreL21 = 0;
            }
        }
        if (str.find('E') != string::npos) {
            break;
        }
    }
    for (pair<int, int> item: vec11) {
        cout << item.first << ":" << item.second << endl;
    }
    cout << scoreW11 << ":" << scoreL11 << endl << endl;
    for (pair<int, int> item: vec21) {
        cout << item.first << ":" << item.second << endl;
    }
    cout << scoreW21 << ":" << scoreL21 << endl;

    return 0;
}