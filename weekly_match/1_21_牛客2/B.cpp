#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 10e6;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int standard = n / 2 + 1;
    cout << a[standard] - 1 << endl;
    return 0;
}