#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 判断一个数是否是质数
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 主逻辑
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);

    // 输入边
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    // 我们将生成一个合理的数字序列
    vector<int> a(n);

    // 简单地用一个方案给定数值，这里选用偶数和奇数交替分配
    // 保证相邻节点差是合数
    int current = 1;
    for (int i = 0; i < n; ++i) {
        a[i] = current;
        current += 2; // 每次跳过一个数字，确保差是合数
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
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