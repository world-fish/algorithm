#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;
    int ans = 0;
    if (x >= a) ans += b;
    if (x >= c) ans += d;
    cout << ans;
    return 0;
}