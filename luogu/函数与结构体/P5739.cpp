#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
 * P5739 【深基7.例7】计算阶乘
 * */

ll sum = 1;
int n;


void factorial(int num) {
    if (num <= n) {
        sum *= num;
        num++;
        factorial(num);
    }
}

int main() {
    cin >> n;
    factorial(1);
    cout << sum << endl;
    return 0;
}