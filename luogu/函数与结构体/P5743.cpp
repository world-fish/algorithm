#include <bits/stdc++.h>

using namespace std;

/*
 * P5743 【深基7.习8】猴子吃桃
 * */

int main() {
    int n;
    cin >> n;
    n--;
    int sum = 1;
    while (n--) {
        ++sum *= 2;
    }
    cout << sum << endl;
    return 0;
}