#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 100001

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a[N], ans = 0, m = 0;
        bool vis[N] = {0};
        bool flag = true;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int temp;
            scanf("%d", &temp);
            if (temp >= 1 && temp <= n && !vis[temp]) {
                vis[temp] = true;
            } else {
                m++;
                a[m] = temp;
            }
        }

        sort(a + 1, a + m + 1);
        int j = 1;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (j <= m && a[j] <= 2 * i) {
                flag = false;
                break;
            }
            if (j <= m && a[j] > i) {
                ans++;
                j++;
            }
        }

        if (flag && j - 1 == m)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}