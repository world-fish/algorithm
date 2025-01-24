#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);

    // 读取 a 数组
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 读取 b 数组
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<long long> changes(n, 0); // 存储每个元素的最大减少值

    // 计算每个元素 a_i 更新后的最小值及差值
    for (int i = 0; i < n; ++i) {
        long long best = a[i];  // 最小值初始化为 a[i]
        for (int j = 0; j < m; ++j) {
            best = min(best, (long long)(a[i] & b[j]));  // 按位与操作取最小
        }
        changes[i] = a[i] - best;  // 记录差值
    }

    // 对差值从大到小排序，选择前 k 个最大差值的元素更新
    sort(changes.begin(), changes.end(), greater<long long>());

    long long result = 0;
    // 更新前 k 个元素，减少最大的差值
    for (int i = 0; i < n; ++i) {
        if (i < k) {
            result += (a[i] - changes[i]);  // 更新后的值
        } else {
            result += a[i];  // 不更新的元素
        }
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // 读取测试用例数
    while (t--) {
        solve();  // 处理每个测试用例
    }

    return 0;
}
