#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        int x = a_i;
        int y = 0;
        for (int j = 0; j < a_i; ++j) {
            int x_j;
            cin >> x_j;
            if (x_j == 1) {
                y++;
            }
        }
        double dirt = (x - y) / (double) x;
        cout << fixed << setprecision(10) << dirt << endl;
    }
}

int main() {
    solve();
    return 0;
}