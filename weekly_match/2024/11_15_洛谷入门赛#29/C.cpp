#include<bits/stdc++.h>

using namespace std;

int solve() {
    int k, d, a;
    scanf("%d/%d/%d", &k, &d, &a);
    int ans;
    if (k - d >= 10) {
        ans = k * (k - d) + a;
    } else if (k >= d) {
        ans = (k - d + 1) * 3 + a;
    } else {
        ans = a * 2;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    int maxVal = 0, maxKey = 0;
    for (int i = 1; i <= t; ++i) {
        int temp = solve();
        if (temp >= maxVal) {
            maxKey = i;
            maxVal = temp;
        }
    }
    cout << maxKey << endl;
    return 0;
}