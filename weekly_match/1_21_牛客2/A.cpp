#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;
        if (num == 4 || num == 7) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}