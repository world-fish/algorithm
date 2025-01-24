#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = INT_MAX;
long a[N];

// 快速读入函数
inline int read() {
    int X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-'; // 标记负数
        ch = getchar();
    }
    while (isdigit(ch)) {
        X = (X << 3) + (X << 1) + (ch ^ 48); // 读入数字
        ch = getchar();
    }
    return w ? -X : X; // 返回读入的数字
}

// 快速输出函数
char F[20]; // 存储数字的字符数组
inline void write(ll x) {
    if (x == 0) {
        putchar('0'); // 输出0
        return;
    }
    if (x < 0) {
        putchar('-'); // 输出负号
        x = -x;
    }
    int cnt = 0;
    while (x > 0) {
        F[cnt++] = x % 10 + '0'; // 存储各位数字
        x /= 10; // 除以10以得到下位
    }
    while (cnt > 0) {
        putchar(F[--cnt]); // 反向输出
    }
}

void solve() {

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}