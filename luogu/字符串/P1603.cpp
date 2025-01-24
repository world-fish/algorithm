#include <bits/stdc++.h>

using namespace std;

/*
 * P1603 斯诺登的密码
 * */

unordered_map<string, int> myMap = {
        {"one",       1},
        {"two",       2},
        {"three",     3},
        {"four",      4},
        {"five",      5},
        {"six",       6},
        {"seven",     7},
        {"eight",     8},
        {"nine",      9},
        {"ten",       10},
        {"eleven",    11},
        {"twelve",    12},
        {"thirteen",  13},
        {"fourteen",  14},
        {"fifteen",   15},
        {"sixteen",   16},
        {"seventeen", 17},
        {"eighteen",  18},
        {"nineteen",  19},
        {"twenty",    20},
        {"a",         1},
        {"both",      2},
        {"another",   1},
        {"first",     1},
        {"second",    2},
        {"third",     3}
};


int main() {
    string str;
    vector<int> arr;
    for (int i = 0; i < 6; i++) {
        cin >> str;
        if (myMap.count(str) > 0) {
            int temp = myMap[str] * myMap[str] % 100;
            if (temp == 0) continue;
            arr.push_back(temp);
        }
    }
    if (arr.empty()) {
        cout << 0;
        return 0;
    }
    sort(arr.begin(), arr.end());
    cout << arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < 10) cout << 0;
        cout << arr[i];
    }
    return 0;
}