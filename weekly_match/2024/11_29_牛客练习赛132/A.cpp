#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> b(n);
    int left = 0, right = n - 1, num = 0;
    while (left <= right) {
        if (left == right) {
            b[left++] = a[num++];
        } else {
            b[left++] = a[num++];
            b[right--] = a[num++];
        }
    }

    double area = 0;
    for (int i = 1; i < n; i++) {
        double maxVal = max(b[i] * 1.0, b[i - 1] * 1.0);
        double minVal = min(b[i] * 1.0, b[i - 1] * 1.0);
        area += (maxVal + minVal) / 2.0;
    }

    printf("%.2f\n", area);
}

int main() {
    solve();
    return 0;
}