#include <bits/stdc++.h>

using namespace std;

/*
 * P5736 【深基7.例2】质数筛
 * */

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int prime;
    while (n--) {
        cin >> prime;
        if (isPrime(prime)) cout << prime << ' ';
    }
    return 0;
}