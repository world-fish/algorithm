#include <bits/stdc++.h>

using namespace std;

void solve() {

}

int main() {
    vector<int> icpc(4);
    vector<int> ccpc(4);
    for (int &i: icpc) {
        cin >> i;
    }
    for (int &i: ccpc) {
        cin >> i;
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j) continue;
            int dif = (icpc[i] - icpc[j]) * (ccpc[i] - ccpc[j]);
            if (dif < 0) ans++;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}