#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(m); // 记录打印的文件
    vector<int> brr(m, 0); // 记录打印时间
    vector<vector<int>> st(n, vector<int>(3)); // 记录每个文件的打印时间和开始时间

    for (int i = 0; i < n; ++i) {
        cin >> st[i][0] >> st[i][1];
        st[i][2] = i + 1;
    }
    sort(st.begin(), st.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    for (auto &item: st) {
        int key = -1;
        int minVal = INT_MAX;
        for (int i = 0; i < m; ++i) {
            if (brr[i] <= item[1]) {
                arr[i].push_back(item[2]);
                brr[i] = item[0] + item[1];
                key = -1;
                break;
            } else {
                if (brr[i] < minVal) {
                    key = i;
                    minVal = brr[i];
                }
            }
        }
        if (key != -1) {
            arr[key].push_back(item[2]);
            brr[key] += item[0];
        }
    }

    for (auto &item: arr) {
        cout << item.size() << " ";
        sort(item.begin(), item.end());
        for (int i: item) {
            cout << i << " ";
        }
        cout << endl;
    }


}

int main() {
    solve();
    return 0;
}