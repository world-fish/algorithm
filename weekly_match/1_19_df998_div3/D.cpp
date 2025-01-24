#include <bits/stdc++.h>

using namespace std;

/*
 * You are given a sequence $a$ consisting of $n$ positive integers.
You can perform the following operation any number of times.
-   Select an index $i$ ($1 \le i &lt; n$), and subtract $\min(a_i,a_{i+1})$ from both $a_i$ and $a_{i+1}$.
Determine if it is possible to make the sequence **non-decreasing** by using the operation any number of times.
 **Input**
Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.
The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).
The second line of each test case contains $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le 10^9$).
It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.
 **Output**
If it is possible to make the sequence **non-decreasing**, print "YES" on a new line. Otherwise, print "NO" on a new line.
You can output the answer in any case. For example, the strings "yEs", "yes", and "Yes" will also be recognized as positive responses.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            cout << "No" << endl;
            return;
        } else {
            a[i + 1] -= a[i];
            a[i] = 0;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
