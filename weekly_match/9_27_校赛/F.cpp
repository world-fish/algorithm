#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        vector<pair<int, int>> ver(n);
        vector<pair<int, int>> hor(n);
        for (int i = 0; i < n; i++) {
            cin >> ver[i].first >> ver[i].second;
            hor[i] = ver[i];
        }

        sort(ver.begin(), ver.end());
        sort(hor.begin(), hor.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        int ans_Alice = 0, ans_Bob = 0;
        set<pair<int, int>> del;  // 使用 set 存储已删除的坐标
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int a_up = 1, a_down = a, b_left = 1, b_right = b;

        char c;
        int k;
        for (int i = 1; i <= m; i++) {
            cin >> c >> k;
            if (c == 'U') {
                a_up += k;
                while (up <= down && ver[up].first < a_up) {
                    if (del.find(ver[up]) == del.end()) {  // 检查坐标是否已删除
                        if (i % 2 == 1) ans_Alice++;
                        else ans_Bob++;
                        del.insert(ver[up]);  // 插入已删除的坐标
                    }
                    up++;
                }
            } else if (c == 'D') {
                a_down -= k;
                while (up <= down && ver[down].first > a_down) {
                    if (del.find(ver[down]) == del.end()) {
                        if (i % 2 == 1) ans_Alice++;
                        else ans_Bob++;
                        del.insert(ver[down]);
                    }
                    down--;
                }
            } else if (c == 'L') {
                b_left += k;
                while (left <= right && hor[left].second < b_left) {
                    if (del.find(hor[left]) == del.end()) {
                        if (i % 2 == 1) ans_Alice++;
                        else ans_Bob++;
                        del.insert(hor[left]);
                    }
                    left++;
                }
            } else if (c == 'R') {
                b_right -= k;
                while (left <= right && hor[right].second > b_right) {
                    if (del.find(hor[right]) == del.end()) {
                        if (i % 2 == 1) ans_Alice++;
                        else ans_Bob++;
                        del.insert(hor[right]);
                    }
                    right--;
                }
            }
        }

        cout << ans_Alice << ' ' << ans_Bob << '\n';
    }

    return 0;
}