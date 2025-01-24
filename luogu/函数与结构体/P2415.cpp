#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
 * P2415 集合求和
 * */

int main() {
    ll temp, num = 0, sum = 0;
    while (cin >> temp) {
        sum += temp;
        num++;
    }
    cout << (long long) (sum * pow(2, num - 1));
    return 0;
}