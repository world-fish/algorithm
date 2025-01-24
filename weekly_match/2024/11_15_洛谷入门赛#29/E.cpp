#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    vector<int> arr(5, 0);
    while (n--) {
        int maxVal = 0, temp;
        for (int i = 0; i < 5; ++i) {
            cin >> temp;
            if (x >= temp) maxVal = max(maxVal, temp);
        }
        if (maxVal != 0) {
            arr[maxVal - 1]++;
            x -= maxVal;
        }
    }
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;
    cout << x << endl;

}

int main() {
    solve();
    return 0;
}