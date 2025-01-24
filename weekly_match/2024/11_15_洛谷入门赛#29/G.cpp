#include <bits/stdc++.h>

using namespace std;

// 判断三个边能否组成三角形
bool isValidTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// 判断当前数字是否是三角含数
bool isTriangleNumber(int x) {
    vector<int> arr;
    while (x > 0) {
        int digit = x % 10;
        if (digit == 0) return false; // 任意一位为 0 则不符合条件
        arr.push_back(digit);
        x /= 10;
    }
    if (arr.size() != 6) return false; // 确保是六位数
    sort(arr.begin(), arr.end()); // 按照升序排序
    // 尝试将 6 个数分为两组，并检查每组是否可以组成三角形
    do {
        if (isValidTriangle(arr[0], arr[1], arr[2]) && isValidTriangle(arr[3], arr[4], arr[5])) {
            return true;
        }
    } while (next_permutation(arr.begin(), arr.end())); // 生成所有排列
    return false;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (isTriangleNumber(i)) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}