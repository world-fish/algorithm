#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            freq[x[i]]++;
        }

        int score = 0;

        for (int i = 1; i <= n; ++i) {
            int b = k - i;
            if (b > 0 && b <= n && i < b) {
                score += min(freq[i], freq[b]);
            }
        }

        if (k % 2 == 0) {
            int mid = k / 2;
            score += freq[mid] / 2;
        }

        cout << score << "\n";
    }

    return 0;
}
