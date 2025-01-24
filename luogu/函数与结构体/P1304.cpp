#include <bits/stdc++.h>

using namespace std;

/*
 * P1304 哥德巴赫猜想
 * */

bool isPrime(int num) {
    if (num <= 2) return true;
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void Goldbach(int num) {
    for (int i = 2; i <= num / 2; ++i) {
        if (isPrime(i) && isPrime(num - i)) {
            cout << num << "=" << i << "+" << num - i << endl;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        Goldbach(i);
    }
    return 0;
}