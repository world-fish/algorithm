#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        int card;
        scanf("%d", &card);
        s.insert(card);
    }

    vector<int> arr(s.begin(), s.end());
    sort(arr.begin(), arr.end());


    int left = 0, right = 0, maxn = 0;
    while (right != arr.size()) {
        if ((arr[right] - arr[left]) - (right - left) > k) {
            left++;
        } else {
            maxn = max(maxn, right - left + k + 1);
            right++;
        }
    }


    cout << min(maxn, m) << endl;
}

int main() {
    solve();
    return 0;
}