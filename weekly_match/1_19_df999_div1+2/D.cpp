#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> count_a, count_b;
    int a, b, a_sum = 0, b_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        count_a[a]++;
        a_sum += a;
    }

    for (int i = 0; i < m; ++i) {
        cin >> b;
        count_b[b]++;
        b_sum += b;
    }
    if (a_sum != b_sum) {
        cout << "NO" << endl;
        return;
    }
    queue<int> q;
    for (auto i: count_b) {
        for (int j = 0; j < i.second; ++j) {
            q.push(i.first);
        }

    }
    while (!q.empty()) {
        if (q.size() > n) {
            cout << "NO" << endl;
            return;
        }
        int top = q.front();
        q.pop();

        if (count_a[top] != 0) {
            --count_a[top];
            --n;
        } else {
            if (top == 1) {
                cout << "NO" << endl;
                return;
            }
            int t = top / 2;
            if (top % 2 == 0) {
                q.push(t);
                q.push(t);
            } else {
                q.push(t);
                q.push(t + 1);
            }
        }
    }
    for (auto i: count_a) {
        if (i.second != 0) {
            cout << "NO" << endl;
            return;
        }

    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}