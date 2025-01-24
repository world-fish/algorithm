#include <bits/stdc++.h>

using namespace std;

/*
 * P5737 【深基7.例3】闰年展示
 * */



bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0) {
            return true;
        } else if (year % 400 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> vec;

    while (x <= y) {
        if (isLeapYear(x)) {
            vec.push_back(x);
            x += 4;
        } else {
            x++;
        }
    }
    cout << vec.size() << endl;
    for (int v: vec) {
        cout << v << ' ';
    }


    return 0;
}