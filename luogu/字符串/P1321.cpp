#include <bits/stdc++.h>

using namespace std;

/*
 * P1321 单词覆盖还原
 * */

int main() {
    string str;
    cin >> str;
    int boy = 0, girl = 0;
    for (int i = 0; i < str.size(); ++i) {
        switch (str[i]) {
            case 'b':
                boy++;
                break;
            case 'o':
                if (str[i - 1] != 'b') boy++;
                break;
            case 'y':
                if (str[i - 1] != 'o') boy++;
                break;
            case 'g':
                girl++;
                break;
            case 'i':
                if (str[i - 1] != 'g') girl++;
                break;
            case 'r':
                if (str[i - 1] != 'i') girl++;
                break;
            case 'l':
                if (str[i - 1] != 'r') girl++;
                break;
            default:
                break;
        }
    }
    cout << boy << endl << girl << endl;
}