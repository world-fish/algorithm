#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    // 读取数组
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 计算目标和
    long long targetSum = n * (n + 1) / 2;
    long long currentSum = 0;

    // 当前数组和
    for (int x: arr) {
        currentSum += x;
    }

    // 大于目标的数和小于目标的数
    long long excess = 0; // 需减少的量
    long long deficit = 0; // 需增加的量

    // 计算每个数与目标数的差值
    for (int i = 1; i <= n; ++i) {
        auto it = find(arr.begin(), arr.end(), i);
        if (it == arr.end()) { // 如果目标数不在数组中
            deficit += i; // 需要增加的量
        } else {
            if (*it > i) {
                excess += (*it - i);
            }
        }
    }

    if (currentSum < targetSum) {
        cout << -1 << endl; // 总和小于目标和，无法变成有效排列
    } else {
        // 最小操作数为需要增加的量
        cout << max(excess, deficit) << endl; // 转移数值的最小操作次数
    }

    return 0;
}