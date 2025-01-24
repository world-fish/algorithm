#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename T>
int die(T x) {
    cout << x << endl;
    return 0;
}

#define mod 1000000007
#define INF 1000000000
#define LNF 1e15
#define LOL 12345678912345719ll

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m; // 读取网格的行列数
        string s;
        cin >> s; // 读取路径字符串
        vector<vector<ll>> a;
        // 读取已知的网格数据
        for (int i = 0; i < n; i++) {
            a.push_back(vector<ll>(m));
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int x = 0, y = 0;  // 起始点为 (0, 0)

        // 按照路径 s 更新网格的值
        for (char c: s) {
            if (c == 'D') {  // 向下移动
                long long su = 0;
                for (int i = 0; i < m; i++) {
                    su += a[x][i]; // 计算当前行的和
                }
                a[x][y] = -su; // 使得当前格子的值为该行的负和
                ++x;  // 行号加1，向下移动
            } else {  // 向右移动
                long long su = 0;
                for (int i = 0; i < n; i++) {
                    su += a[i][y]; // 计算当前列的和
                }
                a[x][y] = -su; // 使得当前格子的值为该列的负和
                ++y;  // 列号加1，向右移动
            }
        }

        // 处理最后一个格子，确保它满足行列和为零
        long long su = 0;
        for (int i = 0; i < m; i++) {
            su += a[n - 1][i]; // 计算最后一行的和
        }
        a[n - 1][m - 1] = -su; // 使得最后一个格子为该行的负和

        // 输出恢复后的网格
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";  // 输出每个格子的值
            }
            cout << endl;  // 换行
        }
    }
    return 0;
}
